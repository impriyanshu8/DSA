class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<int,int> freq;

        // comparator: returns true if a is "better" (higher priority) than b
        auto cmp = [](const pair<int,int>& a, const pair<int,int>& b){
            if (a.first == b.first) return a.second > b.second; // larger value wins on tie
            return a.first > b.first; // higher frequency wins
        };

        multiset<pair<int,int>, decltype(cmp)> top(cmp), rest(cmp);
        long long sumTop = 0;
        vector<long long> ans;

        auto erasePair = [&](const pair<int,int>& p){
            auto itTop = top.find(p);
            if (itTop != top.end()) {
                sumTop -= 1LL * p.first * p.second;
                top.erase(itTop);
                return;
            }
            auto itRest = rest.find(p);
            if (itRest != rest.end()) rest.erase(itRest);
        };

        auto insertToRest = [&](const pair<int,int>& p){
            rest.insert(p);
        };

        auto moveToTop = [&](const pair<int,int>& p){
            // p must be present in rest
            auto it = rest.find(p);
            if (it != rest.end()) rest.erase(it);
            top.insert(p);
            sumTop += 1LL * p.first * p.second;
        };

        auto moveToRest = [&](const pair<int,int>& p){
            // p must be present in top
            auto it = top.find(p);
            if (it != top.end()) {
                top.erase(it);
                sumTop -= 1LL * p.first * p.second;
                rest.insert(p);
            }
        };

        auto balance = [&](){
            // ensure top size <= x
            while ((int)top.size() > x) {
                // move the worst element from top to rest
                auto worstTopIt = prev(top.end()); // comparator makes begin the best
                pair<int,int> p = *worstTopIt;
                moveToRest(p);
            }

            // ensure top size >= x (if possible)
            while ((int)top.size() < x && !rest.empty()) {
                // move the best from rest to top
                auto bestRestIt = rest.begin();
                pair<int,int> p = *bestRestIt;
                moveToTop(p);
            }

            // Now swap while best in rest is better than worst in top
            while (!rest.empty() && !top.empty()) {
                auto bestRestIt = rest.begin();
                auto worstTopIt = prev(top.end());
                pair<int,int> bestRest = *bestRestIt;
                pair<int,int> worstTop = *worstTopIt;
                // if bestRest is better than worstTop, swap them
                // comparator cmp returns true when a is better than b
                if (cmp(bestRest, worstTop)) {
                    // swap
                    moveToTop(bestRest);   // removes from rest, inserts to top, updates sum
                    moveToRest(worstTop);  // removes from top, inserts to rest, updates sum
                } else break;
            }
        };

        auto add = [&](int num) {
            if (freq.count(num)) {
                // remove old pair
                pair<int,int> oldP = {freq[num], num};
                erasePair(oldP);
            }
            freq[num]++;
            insertToRest({freq[num], num});
            balance();
        };

        auto remove = [&](int num) {
            pair<int,int> oldP = {freq[num], num};
            erasePair(oldP);
            freq[num]--;
            if (freq[num] == 0) freq.erase(num);
            else insertToRest({freq[num], num});
            balance();
        };

        // build first window
        for (int i = 0; i < k; ++i) add(nums[i]);
        balance();
        ans.push_back(sumTop);

        for (int i = k; i < n; ++i) {
            remove(nums[i - k]);
            add(nums[i]);
            balance();
            ans.push_back(sumTop);
        }

        return ans;
    }
};
