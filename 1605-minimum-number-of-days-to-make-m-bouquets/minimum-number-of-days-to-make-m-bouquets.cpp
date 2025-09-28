class Solution {
public:
    bool bouqetsPossible(vector<int>& bloomDay,int m, int k, int days){
        int count =0;
        int cnofb = 0;
        int n = bloomDay.size();
        for(int i=0; i<n; i++){
            if(bloomDay[i]<=days){
                count++;
            }
            else{
                cnofb += (count/k);
                count = 0;
            }
        }
        cnofb += (count/k);
        return (cnofb >= m) ;

    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val = m * 1ll * k * 1ll;
        if (val > n) return -1;
        int low = 1, high = *max_element(bloomDay.begin(),bloomDay.end());
       
        while(low<high){
            int mid = low + (high-low)/2;
            if(bouqetsPossible(bloomDay, m, k, mid)){
                
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};