class Solution {
private:
    long long dfs(std::vector<std::vector<int>>& grid, int r, int c, int m, int n) {
        // Base case: check bounds and if the current cell is water/visited (value <= 0)
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] <= 0) {
            return 0;
        }
        
        // Take the value of the current land cell
        long long current_value = grid[r][c];
        
        // "Sink" the cell by changing its value to 0 to avoid using a separate visited matrix
        grid[r][c] = 0;
        
        // Traverse horizontally and vertically (4-directional DFS)
        long long sum = current_value;
        sum += dfs(grid, r + 1, c, m, n);
        sum += dfs(grid, r - 1, c, m, n);
        sum += dfs(grid, r, c + 1, m, n);
        sum += dfs(grid, r, c - 1, m, n);
        
        return sum;
    }

public:
    int countIslands(std::vector<std::vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If we encounter an unvisited land cell, explore the entire island
                if (grid[i][j] > 0) {
                    long long total_island_value = dfs(grid, i, j, m, n);
                    
                    // Check if the accumulated sum is divisible by k
                    if (total_island_value % k == 0) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};