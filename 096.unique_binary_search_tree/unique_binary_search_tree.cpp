class Solution {
public:
    int numTrees(int n) {
        long long res = 1;
        for (int i = 0; i < n; i++) {
            res = res * (2 * n - i) / (i + 1);
        }
        return res / (1 + n);
    }
};
