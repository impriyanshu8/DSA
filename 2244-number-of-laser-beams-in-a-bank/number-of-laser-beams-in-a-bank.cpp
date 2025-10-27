class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, res = 0, curr = 0;

        for (int i = 0; i < bank.size(); i++) {
            curr = 0;
            for (char c : bank[i]) {
                if (c == '1') curr++;
            }

            if (curr > 0) {
                res += prev * curr;
                prev = curr;
            }
        }

        return res;
    }
};
