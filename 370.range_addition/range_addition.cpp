class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);
        for (auto update: updates) {
            res[update[0]] += update[2];
            if (update[1] + 1 != res.size())
                res[update[1] + 1] -= update[2];
        }
        int cur = 0;
        for (int i = 0; i < res.size(); i++) {
            cur += res[i];
            res[i] = cur;
        }
        return res;
    }
};
