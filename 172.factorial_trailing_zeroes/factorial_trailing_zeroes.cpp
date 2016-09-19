class Solution {
public:
    int trailingZeroes(int n) {
        int num2 = 0;
        int num5 = 0;
        long div2 = 2;
        long div5 = 5;
        while (div2 < INT_MAX && div2 <= n) {
            num2 += n / div2;
            div2 *= 2;
        }
        while (div5 < INT_MAX && div5 <= n) {
            num5 += n / div5;
            div5 *= 5;
        }
        return min(num2, num5);
    }
};
