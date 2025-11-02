class Solution {
public:
    void generateSum(int sum,int index, vector<int> &candidates,vector<int> &curr, vector<vector<int>>&ans , int target){
        if(sum == target ){
            ans.push_back(curr);
            return;
        }
         if (sum > target || index == candidates.size()) {
            return;
        }
        curr.push_back(candidates[index]);
        generateSum(sum+candidates[index], index, candidates,curr,ans,target);
        curr.pop_back();
        generateSum(sum,index+1,candidates,curr,ans,target);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        generateSum(0,0,candidates,curr,ans,target);
        return ans;
    }
};