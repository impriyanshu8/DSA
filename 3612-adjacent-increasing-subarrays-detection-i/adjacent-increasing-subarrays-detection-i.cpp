class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 1) return true;
        if (n < 2 * k) return false; // need at least 2 non-overlapping subarrays

        // Outer loop → try to find first increasing subarray of length k
        for (int i = 0; i + 2 * k - 1 <= n; i++) {
            bool first = true;
            int count = 1;

            // Check if nums[i..i+k-1] is strictly increasing
            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] > nums[j - 1]) count++;
                else { first = false; break; }
            }

            if (!first || count < k) continue; // not increasing, skip

            // Now check the next consecutive subarray [i+k .. i+2k-1]
            count = 1;
            bool second = true;
            for (int j = i + k + 1; j < i + 2 * k && j < n; j++) {
                if (nums[j] > nums[j - 1]) count++;
                else { second = false; break; }
            }

            if (second && count == k)
                return true; // found two consecutive increasing subarrays
        }

        return false;
    }
};
