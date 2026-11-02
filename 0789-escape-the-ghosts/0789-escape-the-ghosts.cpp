class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        // Your Manhattan distance from (0, 0) to target
        const int myDistance = abs(target[0]) + abs(target[1]);
        
        // Check every ghost's Manhattan distance to target
        for (const vector<int>& ghost : ghosts) {
            int ghostDistance = abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]);
            if (ghostDistance <= myDistance) {
                return false; // Ghost can reach target at the same time or faster
            }
        }
        
        return true; // You reach the target first
    }
};
