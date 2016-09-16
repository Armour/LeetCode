class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int st = 0;
        int ed = 0;
        int ans = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < s.length(); i++) {
            if (m.find(s[i]) != m.end() && m[s[i]] >= st) {
                st = m[s[i]] + 1;
            }
            ed = i;
            m[s[i]] = i;
            ans = max(ans, ed - st + 1);
        }
        return ans;
    }
};
