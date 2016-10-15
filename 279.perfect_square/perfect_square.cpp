class Solution {
public:
    bool flag = false;
    
    void search(int depth, int goal, int maxn) {
        if (flag) return;
        if (depth == 0) {
            flag = (goal == 0);
        }
        if (maxn * maxn * depth < goal) return;
        for (int i = maxn; i >= 1; i--) {
            if (goal - i * i < 0) continue;
            search(depth - 1, goal - i * i, i);
        }
    }   

    int numSquares(int n) {
        int depth = 1;
        while (!flag) {
            search(depth++, n, (int)sqrt(n));
        }
        return depth - 1;
    }
};
