class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<long long, int> m1, m2;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                m1[A[i] + B[j]]++;
            }
        }
        for (int i = 0; i < C.size(); i++) {
            for (int j = 0; j < D.size(); j++) {
                m2[C[i] + D[j]]++;
            }
        }
        int res = 0;
        for (auto p: m1) {
            auto i = m2.find(-p.first);
            if (i != m2.end()) {
                res += p.second * (*i).second;
            }
        }
        return res;
    }
};
