class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);
        int two = 1;
        for (int i = 1; i <= num; i++) {
            if (i >= two * 2) {
                two *= 2;
            }
            res.push_back(res[i - two] + 1);
        }
        return res;
    }
};
