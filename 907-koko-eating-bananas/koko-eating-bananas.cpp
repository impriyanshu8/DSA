class Solution {
public:
    int counttotalhour(int mid, vector<int>& piles) {
        int totalH = 0;
        for (int bananas : piles) {
            totalH += ceil(double(bananas) / double(mid));
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low < high) {
            int mid = low + (high - low) / 2;
            int totalh = counttotalhour(mid, piles);

            if (totalh <= h) {
                high = mid;   // mid might be the answer
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
