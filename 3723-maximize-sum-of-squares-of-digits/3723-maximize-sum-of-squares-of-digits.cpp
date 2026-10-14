class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
         if ((long long)num * 9 < sum) {
            return "";
        }
        
        std::string result = "";
        for (int i = 0; i < num; ++i) {
            int digit = std::min(9, sum);
            result += std::to_string(digit);
            sum -= digit;
        }
        
        return result;
        
    }
};