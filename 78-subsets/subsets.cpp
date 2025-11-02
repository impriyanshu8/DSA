class Solution {
public:
    void generateSubSets(int index,vector<int> &nums,vector<int> &curr,vector<vector<int>> &ans){
        if(index == nums.size()){
            ans.push_back(curr);
            return;
        }
        generateSubSets(index+1,nums,curr,ans);
        curr.push_back(nums[index]);
        generateSubSets(index+1,nums,curr,ans);
        curr.pop_back();
       
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> ans;
       vector<int> curr;
       generateSubSets(0,nums,curr,ans);
       return ans;
    }
};