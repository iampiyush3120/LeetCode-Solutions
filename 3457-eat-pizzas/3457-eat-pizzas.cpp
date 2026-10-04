#include <vector>
#include <algorithm>

class Solution {
public:
    long long maxWeight(std::vector<int>& pizzas) {
        // Step 1: Sort from smallest to largest
        std::sort(pizzas.begin(), pizzas.end());
        
        int n = pizzas.size();
        int totalDays = n / 4;
        int oddDays = (totalDays + 1) / 2;
        int evenDays = totalDays - oddDays;
        
        long long totalWeight = 0;
        
        // This pointer starts at the very heaviest pizza (the end of the array)
        int right = n - 1; 
        
        // Step 2: For Odd Days, we take the absolute heaviest pizza available
        for (int i = 0; i < oddDays; i++) {
            totalWeight += pizzas[right];
            right--; // Move to the next heaviest
        }
        
        // Step 3: For Even Days, we need the second-heaviest pizza.
        // We skip the heaviest one (right) and take the one next to it (right - 1).
        for (int i = 0; i < evenDays; i++) {
            totalWeight += pizzas[right - 1]; 
            right -= 2; // We used up 2 heavy pizzas for this group, so move left by 2
        }
        
        return totalWeight;
    }
};
