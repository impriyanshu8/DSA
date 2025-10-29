class Solution {
public:
    int smallestNumber(int n) {
        long long x = 1;
        while(true){
            long long allSet = (1LL << x) - 1;
            if(allSet >= n){
                return allSet;
            }
            x++;
        }
    }
};