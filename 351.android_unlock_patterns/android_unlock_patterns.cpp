class Solution {
public:
    bool valid(int from, int to, vector<bool> &used) {
        if (from > to) swap(from, to);
        if (from == 1 && to == 3) return used[2];
        if (from == 1 && to == 7) return used[4];
        if (from == 1 && to == 9) return used[5];
        if (from == 3 && to == 7) return used[5];
        if (from == 3 && to == 9) return used[6];
        if (from == 7 && to == 9) return used[8];
        if (from == 2 && to == 8) return used[5];
        if (from == 4 && to == 6) return used[5];
        return true;
    }

    void search(int depth, int prev, int &res, int minDepth, int maxDepth, vector<bool> &used) {
        if (depth > minDepth) {
            res++;
            if (depth > maxDepth) {
                return;
            }
        }
        for (int i = 1; i <= 9; i++) {
            if (used[i]) continue;
            if (valid(prev, i, used)) {
                used[i] = true;
                search(depth + 1, i, res, minDepth, maxDepth, used);
                used[i] = false;
            }
        }
    }

    int numberOfPatterns(int m, int n) {
        vector<bool> used(9, false);
        int res = 0;
        for (int i = 1; i <= 9; i++) {
            used[i] = true;
            search(2, i, res, m, n, used);
            used[i] = false;
        }
        return res;
    }
};
