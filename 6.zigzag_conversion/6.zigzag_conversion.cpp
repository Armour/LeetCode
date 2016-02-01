class Solution {
public:
    string convert(string s, int numRows) {
        vector< vector<char> > vv(numRows);
        string res;
        if (numRows == 1)
            return s;
        int p = 0;
        int mark = 1;
        for (char ch: s) {
            vv[p].push_back(ch);
            if (mark) {
                p++;
                if (p == numRows - 1)
                    mark = 0;
            } else {
                p--;
                if (p == 0)
                    mark = 1;
            }
        }
        for (auto i: vv) {
            for (auto j: i) {
                res += j;
            }
        }
        return res;
    }
};
