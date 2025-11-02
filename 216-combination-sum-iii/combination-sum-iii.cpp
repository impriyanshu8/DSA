class Solution {
public:
    void generateSum(int num,int k, int n, vector<int> &curr, vector<vector<int>> &ans, int sum){
        if(sum == n && curr.size()==k){
            ans.push_back(curr);
            return;
        }
         if (sum > n || curr.size() > k || num > 9) return;
        curr.push_back(num);
        generateSum(num+1,k,n,curr,ans,sum+num);
        curr.pop_back();
        generateSum(num+1,k,n,curr,ans,sum);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        generateSum(1,k,n,curr,ans,0);
        return ans;
    }
};