class Solution {
public:
    int findNthDigit(int n) {
        long num = 9;
        int depth = 1;
        while (n > num * depth) {
            n -= num * depth;
            num *= 10;
            depth++;
        }
        long start = pow(10, depth - 1);
        long now = start + (n - 1) / depth;
        n = (n - 1) % depth;
        vector<int> v;
        while (now) {
            v.push_back(now % 10);
            now /= 10;
        }
        reverse(v.begin(), v.end());
        return v[n];
    }
};
