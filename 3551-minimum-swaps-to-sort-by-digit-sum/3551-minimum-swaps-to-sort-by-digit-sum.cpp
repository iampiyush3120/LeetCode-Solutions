class Solution {
public:
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int minSwaps(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> sortedNums = nums;

        // Custom sort: primary by digit sum, secondary by numeric value
        std::ranges::sort(sortedNums, [](int a, int b) {
            int sumA = 0, tempA = a;
            while (tempA > 0) { sumA += tempA % 10; tempA /= 10; }
            
            int sumB = 0, tempB = b;
            while (tempB > 0) { sumB += tempB % 10; tempB /= 10; }

            if (sumA != sumB) return sumA < sumB;
            return a < b;
        });

        // Map each value in the sorted array to its target index
        std::unordered_map<int, int> numToIndex;
        for (int i = 0; i < n; ++i) {
            numToIndex[sortedNums[i]] = i;
        }

        std::unordered_set<int> seen;
        int ans = 0;

        // Cycle detection to find minimum swaps
        for (int i = 0; i < n; ++i) {
            if (seen.contains(i) || numToIndex[nums[i]] == i) {
                continue;
            }

            int cycleSize = 0;
            int j = i;
            while (seen.insert(j).second) {
                j = numToIndex[nums[j]];
                ++cycleSize;
            }
            if (cycleSize > 1) {
                ans += (cycleSize - 1);
            }
        }

        return ans;
    }
};