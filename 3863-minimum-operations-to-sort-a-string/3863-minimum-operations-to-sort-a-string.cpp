class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        
        // Case 0: Check if already sorted
        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }
        
        // Case 1: Unsorted and size is 2
        if (n == 2) {
            return -1;
        }
        
        // Find global minimum and maximum characters
        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());
        
        // Case 2: Extreme characters are at their correct boundaries
        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }
        
        // Case 3: Minimum or Maximum character is somewhere in the middle
        for (int i = 1; i < n - 1; ++i) {
            if (s[i] == mn || s[i] == mx) {
                return 2;
            }
        }
        
        // Case 4: Worst case scenario
        return 3;
        
    }
};