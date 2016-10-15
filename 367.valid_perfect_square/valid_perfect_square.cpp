class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num <= 0) return false;
        int st = 1;
        int ed = num;
        int mid = st + (ed - st) / 2;
        while (st <= ed) {
            long long val = (long long)mid * (long long)mid;
            if (val == (long long)num) {
                return true;
            }
            if (val > (long long)num) {
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
            mid = st + (ed - st) / 2;
        }
        return false;
    }
};
