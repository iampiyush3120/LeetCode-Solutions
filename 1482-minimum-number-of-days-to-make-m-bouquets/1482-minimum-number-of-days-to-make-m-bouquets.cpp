class Solution {
public:
    bool possible(vector<int>& bloomDay, int m, int k, int day) {

        int bouquets = 0;
        int flowers = 0;

        for (int i = 0; i < bloomDay.size(); i++) {

            // Flower bloom ho chuka hai
            if (bloomDay[i] <= day) {
                flowers++;

                // k adjacent flowers mil gaye
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            }
            else {
                // Adjacent sequence break
                flowers = 0;
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        // Total flowers hi kam hain
        if ((long long)m * k > bloomDay.size())
            return -1;

        int low = *min_element(bloomDay.begin(),
                               bloomDay.end());

        int high = *max_element(bloomDay.begin(),
                                bloomDay.end());

        while (low < high) {

            int mid = low + (high - low) / 2;

            if (possible(bloomDay, m, k, mid)) {
                // mid possible hai
                // aur minimum day try karo
                high = mid;
            }
            else {
                // mid possible nahi hai
                low = mid + 1;
            }
        }

        return low;
    }
};