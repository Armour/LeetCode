// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int st = 1;
        int ed = n;
        int mid = st + (ed - st) / 2;
        while (st <= ed) {
            if (guess(mid) == 0) {
                return mid;
            } else if (guess(mid) < 0) {
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
            mid = st + (ed - st) / 2;
        }
        return 0;
    }
};
