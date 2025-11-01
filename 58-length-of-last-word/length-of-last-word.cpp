class Solution {
public:
    int lengthOfLastWord(string s) {
        int count =0;
        int ans = 0;
        for(char ch:s){
            if(ch == ' '){
                count = 0;
            }
            else{
                count++;
                ans = count;
            }
           
        }
        return ans;
    }
};