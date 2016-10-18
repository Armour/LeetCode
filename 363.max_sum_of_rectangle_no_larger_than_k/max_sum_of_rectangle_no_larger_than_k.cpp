class Solution {
public:
    int maxSumSubarray(vector<int>& m, int k) {
        vector<int> sum = m;
        for (int i = 1; i < m.size(); i++) {
            sum[i] += sum[i - 1]; 
        }
        int res = INT_MIN;
        set<int> s;
        s.insert(0);
        for (int i = 0; i < m.size(); i++) {
            auto it = s.lower_bound(sum[i] - k);
            if (it != s.end()) {
                res = max(res, sum[i] - *it);
            }
            s.insert(sum[i]);
        }
        return res;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        vector<vector<int>> sum = matrix;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                sum[i][j] += sum[i][j - 1];
            }
        }
        int res = INT_MIN;
        for (int l = 0; l < matrix[0].size(); l++) {
            for (int r = l; r < matrix[0].size(); r++) {
                vector<int> m;  
                for (int i = 0; i < matrix.size(); i++) {
                    if (l == 0) {
                        m.push_back(sum[i][r]);
                    } else {
                        m.push_back(sum[i][r] - sum[i][l - 1]);
                    }
                }
                res = max(res, maxSumSubarray(m, k));
            }
        }
        return res;
    }
};
