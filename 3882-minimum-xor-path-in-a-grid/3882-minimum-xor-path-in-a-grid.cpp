class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // maximum possible XOR value (10 bits range = 0 to 1023)
        const int MAX_XOR = 1024; 
        
        // dp[j][k] tells if XOR value 'k' is reachable at column 'j'
        vector<vector<bool>> dp(n, vector<bool>(MAX_XOR, false));
        
        // Base case: starting cell (0,0)
        int startVal = grid[0][0];
        if (startVal < MAX_XOR) {
            dp[0][startVal] = true;
        }
        
        // Initialize the first row (can only move right)
        for (int j = 1; j < n; ++j) {
            int val = grid[0][j];
            for (int k = 0; k < MAX_XOR; ++k) {
                if (dp[j - 1][k] && (k ^ val) < MAX_XOR) {
                    dp[j][k ^ val] = true;
                }
            }
        }
        
        // Fill the rest of the grid row by row
        for (int i = 1; i < m; ++i) {
            vector<vector<bool>> next_dp(n, vector<bool>(MAX_XOR, false));
            
            for (int j = 0; j < n; ++j) {
                int val = grid[i][j];
                
                for (int k = 0; k < MAX_XOR; ++k) {
                    // Coming from UP (previous row, same column)
                    if (dp[j][k]) {
                        if ((k ^ val) < MAX_XOR) {
                            next_dp[j][k ^ val] = true;
                        }
                    }
                    // Coming from LEFT (current row, previous column)
                    if (j > 0 && next_dp[j - 1][k]) {
                        if ((k ^ val) < MAX_XOR) {
                            next_dp[j][k ^ val] = true;
                        }
                    }
                }
            }
            dp = move(next_dp); // Move to the next row
        }
        
        // Find the minimum reachable XOR value at the destination (m-1, n-1)
        for (int k = 0; k < MAX_XOR; ++k) {
            if (dp[n - 1][k]) {
                return k;
            }
        }
        
        return -1;
    }
};