// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int res = 0;
        int st = 1;
        int ed = n;
        int mid = st + (ed - st) / 2;
        while (st <= ed) {
            if (isBadVersion(mid)) {
                res = mid;
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
            mid = st + (ed - st) / 2;
        }
        return res;
    }
};
