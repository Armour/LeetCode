class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int res = 0;
        int sum = 0;
        int f = 0;
        for (int i = 0; i < A.size(); i++) {
            sum += A[i];
            f += A[i] * i;
        }
        res = f;
        for (int i = A.size() - 1; i >= 1; i--) {
            f += sum;
            f -= A[i] * A.size();
            res = max(res, f);
        }
        return res;
    }
};
