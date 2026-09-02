class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int low = 0;
        int high = 0;

        // Minimum capacity = maximum package
        // Maximum capacity = total weight
        for (int x : weights) {
            low = max(low, x);
            high += x;
        }

        while (low < high) {

            int mid = low + (high - low) / 2;

            int requiredDays = 1;
            int currentWeight = 0;

            for (int x : weights) {

                if (currentWeight + x > mid) {

                    requiredDays++;
                    currentWeight = 0;
                }

                currentWeight += x;
            }

            // mid capacity possible hai
            if (requiredDays <= days) {
                high = mid;
            }

            // mid capacity chhoti hai
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};