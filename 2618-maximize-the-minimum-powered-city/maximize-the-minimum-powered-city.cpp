class Solution {
public:
    // Helper function to check if we can make all cities have at least 'target' power
    bool canAchieve(long long target, vector<long long>& power, int r, long long k) {
        int n = power.size();
        vector<long long> added(n, 0);  // track newly added stations
        long long used = 0;             // total new stations used
        long long window = 0;           // running sum of extra power in current window

        for (int i = 0; i < n; i++) {
            // Slide the window forward: remove stations that are no longer in range
            if (i - r - 1 >= 0) window -= added[i - r - 1];

            // Effective power at city i = current power + window (added coverage)
            long long currPower = power[i] + window;

            // If power is below target, we need to add more stations
            if (currPower < target) {
                long long need = target - currPower;
                used += need;
                if (used > k) return false;  // too many new stations → not possible

                int pos = min(n - 1, i + r); // place new stations as far right as possible
                added[pos] += need;
                window += need;              // these new stations will cover future cities too
            }
        }
        return true;  // all cities reached target power within k stations
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();

        // Step 1: Compute initial power for each city using prefix sum
        vector<long long> prefix(n + 1, 0), power(n, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + stations[i];

        for (int i = 0; i < n; i++) {
            int left = max(0, i - r);
            int right = min(n - 1, i + r);
            power[i] = prefix[right + 1] - prefix[left];
        }

        // Step 2: Binary search for the maximum possible minimum power
        long long low = 0, high = *max_element(power.begin(), power.end()) + k, ans = 0;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (canAchieve(mid, power, r, k)) {
                ans = mid;        // possible to achieve mid → try higher
                low = mid + 1;
            } else {
                high = mid - 1;   // not possible → go lower
            }
        }

        return ans;
    }
};
