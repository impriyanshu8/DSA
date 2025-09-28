class Solution {
public:
    int getSum(vector<int>& nums, int mid){
        int sum = 0;
        for(int num : nums){
            sum += (num + mid - 1) / mid; // ceil division
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        
        while(low < high){
            int mid = low + (high - low) / 2;
            if(getSum(nums, mid) <= threshold){
                high = mid; // mid is valid, try smaller
            } else {
                low = mid + 1; // mid too small
            }
        }
        return low;
    }
};
