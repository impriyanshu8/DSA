#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i <= n - k; i++) {
            unordered_map<int, int> freq;

            // Count frequencies in current window
            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }

            // Convert to vector of pairs for sorting
            vector<pair<int, int>> v(freq.begin(), freq.end());

            // Sort by frequency desc, then value desc
            sort(v.begin(), v.end(), [](auto &a, auto &b) {
                if (a.second == b.second)
                    return a.first > b.first; // higher value first if freq same
                return a.second > b.second;  // higher freq first
            });

            // Pick top x numbers
            unordered_set<int> topX;
            for (int j = 0; j < v.size() && j < x; j++) {
                topX.insert(v[j].first);
            }

            // Compute sum of elements in window that belong to topX
            int total = 0;
            for (int j = i; j < i + k; j++) {
                if (topX.count(nums[j])) total += nums[j];
            }

            ans.push_back(total);
        }

        return ans;
    }
};
