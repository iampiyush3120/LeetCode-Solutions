class Solution {
    void solve(int k, int target, int i, vector<vector<int>>& answer, vector<int>& temp) {
        // Base case 1
        if (k == 0) {
            if (target == 0) {
                answer.push_back(temp);
            }
            return;
        }
        
        // Base case 2
        if (target < 0 || i > 9) return;

        // Recursion case - Element ko include kiya
        temp.push_back(i);
        solve(k - 1, target - i, i + 1, answer, temp);
        temp.pop_back(); // Backtrack

        // Element ko exclude kiya
        solve(k, target, i + 1, answer, temp);
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> answer;
        vector<int> temp;
        // Arguments ka order aur naam sahi kiya (i=1 ko yahan se pass kiya hai)
        solve(k, n, 1, answer, temp); 
        return answer;
    }
};
