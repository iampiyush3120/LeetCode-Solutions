
class Solution {
private:
    long long MOD = 1e9 + 7;
    vector<vector<long long>> table;

    // Precompute Pascal's Triangle for Combinations (nCr)
    void precomputeCombinations(int n) {
        table.assign(n + 1, vector<long long>(n + 1, 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % MOD;
            }
        }
    }

    long long dfs(vector<int>& nums) {
        if (nums.size() <= 2) return 1;

        int root = nums[0];
        vector<int> leftSubtree, rightSubtree;

        // Partition elements into left and right subtrees
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < root) {
                leftSubtree.push_back(nums[i]);
            } else {
                rightSubtree.push_back(nums[i]);
            }
        }

        // Recursively solve for subtrees
        long long leftWays = dfs(leftSubtree);
        long long rightWays = dfs(rightSubtree);

        // Interleave left and right subtree elements
        long long totalWays = table[leftSubtree.size() + rightSubtree.size()][leftSubtree.size()];

        return (((totalWays * leftWays) % MOD) * rightWays) % MOD;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        precomputeCombinations(n);
        
        // Subtract 1 to exclude the original array order
        return (dfs(nums) - 1 + MOD) % MOD; 
    }
};