class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int min_sum = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int current_sum = 0;
            for (int j = i; j < n; ++j) {
                current_sum += nums[j];
                int len = j - i + 1;

                // Stop expanding if the subarray exceeds maximum allowed length r
                if (len > r) {
                    break;
                }

                // Check if length is within [l, r] and sum is strictly positive
                if (len >= l && current_sum > 0) {
                    min_sum = min(min_sum, current_sum);
                }
            }
        }

        return (min_sum == INT_MAX) ? -1 : min_sum;
    }
};