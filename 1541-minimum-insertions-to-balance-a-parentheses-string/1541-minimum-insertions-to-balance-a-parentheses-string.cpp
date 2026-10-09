class Solution {
public:
    int minInsertions(string s) {
        int neededRight = 0; // Tracks required closing ')' brackets (2 for each '(')
        int missingLeft = 0; // Tracks missing opening '(' brackets
        int missingRight = 0; // Tracks missing single ')' when an odd ')' comes after '('

        for (const char c : s) {
            if (c == '(') {
                if (neededRight % 2 == 1) {
                    // We need an even number of ')' to close, but found a new '('
                    ++missingRight;
                    --neededRight;
                }
                neededRight += 2;
            } else { // c == ')'
                if (--neededRight < 0) {
                    // Extra closing ')' without a matching '('
                    ++missingLeft;
                    neededRight += 2; // Compensate for the deficit
                }
            }
        }

        return neededRight + missingLeft + missingRight;
    }
};
