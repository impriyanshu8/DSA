class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int>freq;
        for(char ch:s){
            freq[ch]++;
        }
    vector<pair<char, int>> vec(freq.begin(), freq.end());
    
    sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

    string result="";
    for(auto &p:vec){
            result.append(p.second, p.first);
        }
    return result;   
    } 
};