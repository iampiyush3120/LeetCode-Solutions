class Solution {
public:
    int minMoves(std::vector<int>& nums) {
        long long total_sum = 0;
        int min_val = nums[0];
        
        for (int num : nums) {
            total_sum += num;
            min_val = std::min(min_val, num);
        }
        
        return total_sum - (long long)min_val * nums.size();
    }
};