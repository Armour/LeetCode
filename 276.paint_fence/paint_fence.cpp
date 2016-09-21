class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0) return 0;
        else if (n == 1) return k;
        else if (n == 2) return k * k;
        else {
            int fsame = k;
            int fdiff = k * (k - 1);
            for (int i = 2; i < n; i ++) {
                int old_fsame = fsame;
                int old_fdiff = fdiff;
                fsame = old_fdiff;
                fdiff = (old_fdiff + old_fsame) * (k - 1);
            }
            return fsame + fdiff;
        }
    }
};
