class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        int cnt = 0;
        string res = "";
        if (s.length() == 0 || t.length() == 0) return res;
        for (auto c: t) {
            m[c]++;
        }
        int st = 0;
        int ed = 0;
        for (int i = 0; i < s.length(); i++) {
            ed = i;
            if (m.find(s[i]) != m.end()) {
                if (--m[s[i]] >= 0) cnt++;
                while (m.find(s[st]) == m.end() || m[s[st]] < 0) {
                    if (m.find(s[st]) != m.end()) {
                        m[s[st]]++;
                    }
                    st++;
                }
                if (cnt == t.length()) {
                    if (res.compare("") == 0 || res.length() > (ed - st + 1)) {
                        res = s.substr(st, ed - st + 1);
                    }
                }
            }
        }
        return res;
    }
};
