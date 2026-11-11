class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // Strategy 1: Buy only individual items for need1 and need2
        long long a = 1LL * need1 * cost1 + 1LL * need2 * cost2;
        
        // Strategy 2: Buy 'both' items to cover the maximum of both needs
        long long b = 1LL * costBoth * max(need1, need2);
        
        // Strategy 3: Buy 'both' items for the overlapping minimum need, 
        // then buy the remaining shortfall using individual items
        int mn = min(need1, need2);
        long long c = 1LL * costBoth * mn 
                    + 1LL * (need1 - mn) * cost1 
                    + 1LL * (need2 - mn) * cost2;
        
        return min({a, b, c});
    }
};
