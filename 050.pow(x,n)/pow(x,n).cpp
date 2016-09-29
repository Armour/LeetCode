class Solution {
public:
    double fastPow(double x, long n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        double res = fastPow(x, n / 2);
        res *= res;
        if (n % 2 != 0)
            res *= x;
        return res;
    }

    double myPow(double x, int n) {
        int ln = n;
        if (ln < 0) {
            ln = -ln;
            x = 1 / x;
        }
        return fastPow(x, ln);
    }
};
