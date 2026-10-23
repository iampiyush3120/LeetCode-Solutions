class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = -1;
        
        for (int i = 0; i < nums.size(); ++i) {
            // If the element is not in its correct sorted position
            if (nums[i] != i) {
                ans &= nums[i];
            }
        }
        
        // If ans remains -1, it means no elements were misplaced (already sorted) -> return 0.
        // Otherwise, return the calculated maximum k.
        return (ans == -1) ? 0 : ans;
        
    }
};