class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        // 1. Sahi tarike se n ke saare divisors find karein
        std::vector<int> divisors;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (i * i != n) {
                    divisors.push_back(n / i); // Fix: n ki jagah n / i kiya
                }
            }
        }

        // Each divisor k ko validate karein
        for (int k : divisors) {
            bool valid = true;
            int last_max = INT_MIN;

            for (int i = 0; i < n; i += k) {
                int current_min = INT_MAX;
                int current_max = INT_MIN;
                int drops = 0;

                // Local validity check (Cyclic rotation ke liye)
                for (int j = 0; j < k; ++j) {
                    int curr = nums[i + j];
                    int next = nums[i + (j + 1) % k]; // Circular next element

                    if (curr > next) {
                        drops++;
                    }
                    current_min = std::min(current_min, curr);
                    current_max = std::max(current_max, curr);
                }

                // Agar 1 se zyada drop hai toh woh block cyclically sort nahi ho sakta
                if (drops > 1) {
                    valid = false;
                    break;
                }

                // Global sorted order check (pichle block ka max <= agle block ka min)
                if (current_min < last_max) {
                    valid = false;
                    break;
                }

                last_max = current_max;
            }

            if (valid) {
                sum += k;
            }
        }

        return sum;
        
    }
};