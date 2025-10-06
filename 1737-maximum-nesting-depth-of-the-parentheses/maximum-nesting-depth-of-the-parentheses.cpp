class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                count++;
                ans = max(ans, count);  // update max only when '(' increases depth
            } 
            else if (s[i] == ')') {
                count--;
            }
        }
        return ans;
    }
};
