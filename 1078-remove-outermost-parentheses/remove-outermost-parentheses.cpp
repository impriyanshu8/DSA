class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "" ;
        int level = 0;
        for (char ch:s){
            if(ch == '(') {
                if(level>0){
                    result.push_back('(');
                }
                
                    level ++;
                  
             }
             else if(ch == ')'){
                 level --;
                if(level>0){
                    result.push_back(')');
                }   
                
             }
        }
                return result;
    }
};