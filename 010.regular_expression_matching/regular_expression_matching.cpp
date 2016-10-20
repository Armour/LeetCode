class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.length() == 0 && p.length() == 0) return true;
        int lens = s.length();
        int lenp = p.length();
        vector<vector<bool>> f(lens + 1, vector<bool>(lenp + 1, false));
        f[0][0] = true;
        for (int i = 2; i <= lenp; i++) {
            if (p[i - 1] == '*')
                f[0][i] = f[0][i - 2];
        }
        for (int i = 1; i <= lens; i++) {
            for (int j = 1; j <= lenp; j++) {
                if ((p[j - 1] == '.' || s[i - 1] == p[j - 1]) && f[i - 1][j - 1]) f[i][j] = true;
                if (p[j - 1] == '*') {
                    if (f[i][j - 2])
                        f[i][j] = true;
                    if (f[i - 1][j] && (p[j - 2] == '.' || p[j - 2] == s[i - 1]))
                        f[i][j] = true;
                }
            }
        }
        return f[lens][lenp];
    }
};
