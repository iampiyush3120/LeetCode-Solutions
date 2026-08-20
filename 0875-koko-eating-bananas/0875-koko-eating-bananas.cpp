class Solution {
private:
    bool ispossible(vector<int>& piles, int mid, int h) {
        long long hours = 0; // Use long long to prevent integer overflow
        for (int i = 0; i < piles.size(); i++) {
            // Ceiling division formula: (piles[i] + mid - 1) / mid
            hours += (piles[i] + mid - 1) / mid; 
            
            if (hours > h) return false; // Early exit to save time
        }
        return true;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN;
        for (int i = 0; i < piles.size(); i++) {
            if (piles[i] > maxi) {
                maxi = piles[i];
            }
        }
        
        int s = 1, e = maxi;
        int ans = maxi;
        
        while (s <= e) {
            int mid = s + (e - s) / 2; // Prevents potential overflow
            
            if (ispossible(piles, mid, h)) {
                ans = mid;
                e = mid - 1; // Try to find a smaller valid speed
            } else {
                s = mid + 1; // Speed is too slow, increase it
            }
        }
        return ans;
    }
};