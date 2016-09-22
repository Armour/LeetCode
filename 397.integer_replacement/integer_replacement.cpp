class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1) return 0;
        if (n % 2 == 0) return integerReplacement(n / 2) + 1;
        if (n != INT_MAX) return min(integerReplacement(n + 1), integerReplacement(n - 1)) + 1;
        return min(integerReplacement(n - 1), integerReplacement(((n - 1) / 2 + 1) + 1)) + 1;
    }
};
