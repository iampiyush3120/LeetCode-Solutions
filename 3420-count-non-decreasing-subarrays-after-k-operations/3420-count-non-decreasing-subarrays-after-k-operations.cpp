class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long cost = 0;
        
        // Stores {current_value, count_of_elements_with_this_value}
        deque<pair<long long, int>> dq;
        
        int j = n - 1;
        for (int i = n - 1; i >= 0; --i) {
            long long curr = nums[i];
            int count = 1;
            
            // Merge smaller or equal blocks to the right into curr
            while (!dq.empty() && dq.front().first <= curr) {
                auto [val, cnt] = dq.front();
                dq.pop_front();
                cost += (curr - val) * cnt;
                count += cnt;
            }
            dq.push_front({curr, count});
            
            // Shrink window from the right until total cost <= k
            while (cost > k) {
                auto& [val, cnt] = dq.back();
                cost -= (val - nums[j]);
                --cnt;
                if (cnt == 0) {
                    dq.pop_back();
                }
                --j;
            }
            
            // Every subarray starting at i and ending in [i, j] is valid
            ans += (j - i + 1);
        }
        
        return ans;
    }
};