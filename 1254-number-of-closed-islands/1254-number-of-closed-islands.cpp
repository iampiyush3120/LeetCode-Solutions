class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Step 1: Remove all land blocks connected to the grid boundaries
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                // If it's a boundary cell and contains land (0)
                if ((r == 0 || r == rows - 1 || c == 0 || c == cols - 1) && grid[r][c] == 0) {
                    dfs(grid, r, c, rows, cols);
                }
            }
        }
        
        // Step 2: Count the remaining isolated islands inside the interior grid
        int closedIslandsCount = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 0) {
                    closedIslandsCount++;
                    dfs(grid, r, c, rows, cols); // Flood-fill to sink the island
                }
            }
        }
        
        return closedIslandsCount;
    }

private:
    void dfs(std::vector<std::vector<int>>& grid, int r, int c, int rows, int cols) {
        // Base case: Out of bounds or already water (1)
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 1) {
            return;
        }
        
        // Mark the current land cell as water to avoid revisiting (visited check)
        grid[r][c] = 1;
        
        // Explore 4-directional neighbors
        dfs(grid, r + 1, c, rows, cols);
        dfs(grid, r - 1, c, rows, cols);
        dfs(grid, r, c + 1, rows, cols);
        dfs(grid, r, c - 1, rows, cols);
        
    }
};