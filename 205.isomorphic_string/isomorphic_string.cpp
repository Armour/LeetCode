class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        map<char, char> m;
        set<char> used;
        for (int i = 0; i < s.length(); i++) {
            if (m.find(s[i]) == m.end()) {
                if (used.find(t[i]) != used.end()) return false;
                m[s[i]] = t[i];
                used.insert(t[i]);
            } else if (m[s[i]] != t[i]) {
                return false;
            }
        }
        return true;
    }
};
