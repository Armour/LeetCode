class Solution {
public:
    bool isUgly(int num) {
        if (num == 0) return false;
        vector<int> v = {2, 3, 5};
        for (int n: v) {
            while (num % n == 0) {
                num /= n;
            }
        }
        return num == 1;
    }
};
