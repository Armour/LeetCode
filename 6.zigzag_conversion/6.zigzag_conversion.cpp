class Solution {
public:
    string convert(string s, int numRows) {
        char map[numRows][s.length()];
        int stx = 0;
        int sty = 0;
        int dir = 0;
        string ans;
        if (numRows == 1) return s;
        memset(map, ' ', sizeof(map));
        for (int i = 0; i < s.length(); i++) {
            map[stx][sty] = s[i];
            if (dir == 0) {
                stx++;
            } else {
                sty++;
                stx--;
            }
            if (stx == numRows - 1) dir = 1;
            if (stx == 0) dir = 0;
        }
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < s.length(); j++) {
                if (map[i][j] != ' ') {
                    ans += map[i][j];
                }
            }
        }
        return ans;
    }
};
