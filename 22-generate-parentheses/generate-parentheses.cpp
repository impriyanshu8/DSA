class Solution {
public:
    bool isValid(string s) {
        int balance = 0;
        for (char c : s) {
            if (c == '(') balance++;
            else balance--;
            if (balance < 0) return false; // closing before opening
        }
        return balance == 0;
    }

    void generateAll(string curr, int n, vector<string> &ans) {
        if (curr.length() == 2 * n) {
            if (isValid(curr)) ans.push_back(curr);
            return; // stop recursion here
        }

        generateAll(curr + '(', n, ans);
        generateAll(curr + ')', n, ans);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generateAll("", n, ans);
        return ans;
    }
};
