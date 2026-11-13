class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        
        // Track strictly increasing subarray
        for (int i = 1, inc = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                inc++;
                ans = max(ans, inc);
            } else {
                inc = 1;
            }
        }
        
        // Track strictly decreasing subarray
        for (int i = 1, dec = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                dec++;
                ans = max(ans, dec);
            } else {
                dec = 1;
            }
        }
        
        return ans;
    }
};