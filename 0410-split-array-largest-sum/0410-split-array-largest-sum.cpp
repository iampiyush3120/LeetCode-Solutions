class Solution {
public:
    int splitArray(vector<int>& nums, int k) {

        int low = 0;
        int high = 0;

        // Minimum possible answer
        // = maximum element
        for (int x : nums) {
            low = max(low, x);
            high += x;
        }

        while (low < high) {

            int mid = low + (high - low) / 2;

            int subarrays = 1;
            int sum = 0;

            for (int x : nums) {

                if (sum + x > mid) {

                    // New subarray
                    subarrays++;
                    sum = 0;
                }

                sum += x;
            }

            // mid possible hai
            if (subarrays <= k) {
                high = mid;
            }

            // mid possible nahi hai
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};