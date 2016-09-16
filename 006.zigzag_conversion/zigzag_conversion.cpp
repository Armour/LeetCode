class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<vector<char>> zigzag(numRows);
        int flag = -1;
        int cur = 0;
        for (char ch: s) {
            if (cur == numRows - 1 || cur == 0) flag = -flag;
            zigzag[cur].push_back(ch);
            cur += flag;
        }
        string str;
        for (int num = 0; num < numRows; num++) {
            for (char ch: zigzag[num]) {
                str += ch;
            }
        }
        return str;
    }
};
