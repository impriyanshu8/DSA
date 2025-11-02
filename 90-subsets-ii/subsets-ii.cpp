class Solution {
public:
    void generateSubSet(int index, vector<vector<int>>& res, vector<int>& curr, vector<int>& nums) {
        res.push_back(curr);  // Add current subset at every recursion level

        for (int i = index; i < nums.size(); i++) {
            // Skip duplicates at the same recursion depth
            if (i > index && nums[i] == nums[i - 1]) continue;

            curr.push_back(nums[i]);
            generateSubSet(i + 1, res, curr, nums);
            curr.pop_back(); // backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(nums.begin(), nums.end()); // Important for handling duplicates
        generateSubSet(0, res, curr, nums);
        return res;
    }
};
