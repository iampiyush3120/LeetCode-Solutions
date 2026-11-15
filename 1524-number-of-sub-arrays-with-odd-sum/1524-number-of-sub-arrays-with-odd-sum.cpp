class Solution {
public:
    int numOfSubarrays(std::vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long totalOddSubarrays = 0;
        int currentPrefixSum = 0;
        
        // count[0] tracks even prefix sums (initialized to 1 for empty prefix sum 0)
        // count[1] tracks odd prefix sums
        int parityCount[2] = {1, 0}; 

        for (int num : arr) {
            currentPrefixSum += num;
            int parity = currentPrefixSum & 1; // 0 if even, 1 if odd
            
            // Add the count of prefix sums with the opposite parity
            totalOddSubarrays = (totalOddSubarrays + parityCount[parity ^ 1]) % MOD;
            
            // Increment the count for the current parity
            parityCount[parity]++;
        }

        return static_cast<int>(totalOddSubarrays);
    }
};