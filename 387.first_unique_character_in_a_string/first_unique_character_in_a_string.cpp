class Solution {
public:
    int firstUniqChar(string s) {
        if (s.compare("") == 0) return -1;
        unordered_map<char, int> m;
        for (int i = 0; i < s.length(); i++) {
            if (m.find(s[i]) == m.end()) {
                m[s[i]] = i; 
            } else 
                m[s[i]] = -1;
        }
        int ans = s.length();
        for (auto p: m) {
            if (p.second != -1)
                ans = min(ans, p.second);
        }
        return ans == s.length()? -1: ans;
    }
};
