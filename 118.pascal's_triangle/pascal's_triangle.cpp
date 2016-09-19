class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j <= i; j++) {
                res[i].push_back(j == 0 || j == i? 1: res[i-1][j] + res[i-1][j-1]);
            }
        }
        return res;
    }
};
