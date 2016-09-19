class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res(2);
        int flag = 0;
        for (int i = 0; i <= rowIndex; i++) {
            res[flag].clear();
            for (int j = 0; j <= i; j++) {
                res[flag].push_back(j == 0 || j == i? 1: res[1 - flag][j] + res[1 - flag][j - 1]);
            }
            flag = 1 - flag;
        }
        return res[1 - flag];
    }
};
