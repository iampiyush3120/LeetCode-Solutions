class Solution {
public:
    std::string removeStars(std::string s) {
        std::string result = "";
        
        for (char c : s) {
            if (c == '*') {
                // Remove the last added character (LIFO behavior)
                result.pop_back(); 
            } else {
                // Accumulate non-star characters
                result.push_back(c); 
            }
        }
        
        return result;
    }
};