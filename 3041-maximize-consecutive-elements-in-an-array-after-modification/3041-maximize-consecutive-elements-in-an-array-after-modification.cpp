class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        // dp[x] = max length of a consecutive sequence ending at value x
        unordered_map<int, int> dp;
        int max_len = 0;

        for (int num : nums) {
            // Option 1: Increment current num to (num + 1)
            dp[num + 1] = dp[num] + 1;
            
            // Option 2: Keep current num as is
            dp[num] = dp[num - 1] + 1;
            
            max_len = max({max_len, dp[num], dp[num + 1]});
        }

        return max_len;
    }
};