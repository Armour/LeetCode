class Solution {
public:
    int reverse(int x) {
        int sign = x > 0;
        long ans = 0;
        if (!sign)
            x = -x;
        while (x > 0) {
            ans *= 10;
            if (ans >= INT_MAX) return 0;
            ans += x % 10;
            x /= 10;
        }
        if (!sign)
            ans = -ans;
        return ans;
    }
};
