class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.length() == 0 && p.length() == 0) return true;
        int len_s = s.length();
        int len_p = p.length();
        vector<vector<bool>> dp(len_s + 1, vector<bool>(len_p + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= len_p; i++) {
            dp[0][i] = dp[0][i - 1] && p[i - 1] == '*';
        }
        for (int i = 1; i <= len_s; i++) {
            for (int j = 1; j <= len_p; j++) {
                if ((p[j - 1] == '?' || p[j - 1] == s[i - 1]) && dp[i - 1][j - 1])
                    dp[i][j] = true;
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }
        return dp[len_s][len_p];
    }
};
