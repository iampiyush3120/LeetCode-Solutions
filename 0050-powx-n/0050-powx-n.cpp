class Solution {
public:

    double power(double x, long long n) {

        // Base case
        if (n == 0)
            return 1;

        // Recursive call
        double half = power(x, n / 2);

        // n even
        if (n % 2 == 0) {
            return half * half;
        }

        // n odd
        return half * half * x;
    }

    double myPow(double x, int n) {

        long long N = n;

        // Negative power
        if (N < 0) {
            return 1.0 / power(x, -N);
        }

        return power(x, N);
    }
};