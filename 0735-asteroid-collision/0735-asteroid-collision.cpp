class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        std::vector<int> st;

        for (int ast : asteroids) {
            bool destroyed = false;
            // Collision happens only if stack top is moving right (>) 
            // and current asteroid is moving left (<)
            while (!st.empty() && st.back() > 0 && ast < 0) {
                if (std::abs(st.back()) < std::abs(ast)) {
                    st.pop_back(); // Stack top explodes, keep checking `ast`
                    continue;
                } else if (std::abs(st.back()) == std::abs(ast)) {
                    st.pop_back(); // Both explode
                }
                destroyed = true; // Current asteroid explodes
                break;
            }
            if (!destroyed) {
                st.push_back(ast);
            }
        }

        return st;
    }
};