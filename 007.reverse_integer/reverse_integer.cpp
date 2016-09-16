class Solution {
public:
    int reverse(int x) {
        int sign = x > 0;
        long tmpx = x;
        if (!sign) {
            tmpx = -tmpx;
        }
        long long res = 0;
        while (tmpx) {
            res *= 10;
            if (res >= INT_MAX) return 0;
            res += tmpx % 10;
            tmpx /= 10;
        }
        if (!sign) res = -res;
        return res;
    }
};
