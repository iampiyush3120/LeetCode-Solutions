class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {

        const int MOD = 1e9 + 7;

        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size() - 1;

        // powers[i] = 2^i
        vector<long long> powers(nums.size());

        powers[0] = 1;

        for (int i = 1; i < nums.size(); i++) {
            powers[i] = (powers[i - 1] * 2) % MOD;
        }

        long long ans = 0;

        while (left <= right) {

            // Minimum + Maximum valid hai
            if (nums[left] + nums[right] <= target) {

                // nums[left] ko minimum fix karo.
                // left+1 se right tak har element
                // choose / not choose ho sakta hai.
                int count = right - left;

                ans = (ans + powers[count]) % MOD;

                left++;
            }

            else {
                // Sum bada hai → maximum ko chhota karo
                right--;
            }
        }

        return ans;
    }
};