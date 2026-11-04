class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        
        // 1. Sliding Window using Multisets to calculate minOps for each window of size x
        vector<long long> minOps(n - x + 1, 0);
        multiset<int> lower, upper;
        long long lowerSum = 0, upperSum = 0;

        auto balance = [&]() {
            while (lower.size() > upper.size() + 1) {
                int val = *lower.rbegin();
                lower.erase(prev(lower.end()));
                lowerSum -= val;
                upper.insert(val);
                upperSum += val;
            }
            while (lower.size() < upper.size()) {
                int val = *upper.begin();
                upper.erase(upper.begin());
                upperSum -= val;
                lower.insert(val);
                lowerSum += val;
            }
        };

        for (int i = 0; i < n; ++i) {
            if (lower.empty() || nums[i] <= *lower.rbegin()) {
                lower.insert(nums[i]);
                lowerSum += nums[i];
            } else {
                upper.insert(nums[i]);
                upperSum += nums[i];
            }
            balance();

            if (i >= x) {
                int out = nums[i - x];
                auto it = lower.find(out);
                if (it != lower.end()) {
                    lower.erase(it);
                    lowerSum -= out;
                } else {
                    upper.erase(upper.find(out));
                    upperSum -= out;
                }
                balance();
            }

            if (i >= x - 1) {
                long long median = *lower.rbegin();
                long long cost = (median * lower.size() - lowerSum) + (upperSum - median * upper.size());
                minOps[i - x + 1] = cost;
            }
        }

        // 2. DP Table Matrix to pick k non-overlapping windows safely
        int m = minOps.size();
        // dp[i][j] -> Min cost picking 'j' subarrays from suffix starting at window index 'i'
        const long long INF = 1e16; // Use a safe large infinity value to avoid overflow
        vector<vector<long long>> dp(m + 1, vector<long long>(k + 1, INF));

        // Base Case: 0 subarrays required means 0 operations
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = 0;
        }

        // Fill DP table backwards
        for (int i = m - 1; i >= 0; --i) {
            for (int j = 1; j <= k; ++j) {
                // Option 1: Skip this window position
                dp[i][j] = dp[i + 1][j];

                // Option 2: Pick this window (and jump ahead by 'x' indices to avoid overlap)
                if (i + x <= m) {
                    dp[i][j] = min(dp[i][j], minOps[i] + dp[i + x][j - 1]);
                } else if (j == 1) {
                    // Special case: If we only need 1 last subarray and no space left to jump ahead
                    dp[i][j] = min(dp[i][j], minOps[i]);
                }
            }
        }

        return dp[0][k] >= INF ? -1 : dp[0][k];
    }
};