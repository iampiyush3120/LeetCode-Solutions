class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        // 1. Find the index of element 0
        int z = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                z = i;
                break;
            }
        }

        // 2. Check if the array is an ascending cyclic shift
        bool is_ascending_cyclic = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(z + i) % n] != i) {
                is_ascending_cyclic = false;
                break;
            }
        }

        if (is_ascending_cyclic) {
            if (z == 0) return 0; // Already perfectly sorted
            // Path A: Pure left rotations (cost = z)
            // Path B: Reverse -> Rotate left -> Reverse back (cost = 2 + n - z)
            return min(z, 2 + n - z);
        }

        // 3. Check if the array is a descending cyclic shift
        int z_rev = n - 1 - z;
        vector<int> rev = nums;
        reverse(rev.begin(), rev.end());

        bool is_descending_cyclic = true;
        for (int i = 0; i < n; ++i) {
            if (rev[(z_rev + i) % n] != i) {
                is_descending_cyclic = false;
                break;
            }
        }

        if (is_descending_cyclic) {
            // Path C: Rotate left first, then Reverse (cost = ((z + 1) % n) + 1)
            // Path D: Reverse first, then Rotate left (cost = n - z)
            int cost1 = ((z + 1) % n) + 1;
            int cost2 = n - z;
            return min(cost1, cost2);
        }

        // If the permutation cannot be sorted using these operations
        return -1;
    }
};