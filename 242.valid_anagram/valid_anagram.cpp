class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> M;
        for (char ch: s) {
            if (M.find(ch) == M.end()) {
                M[ch] = 1;
            } else {
                M[ch] = M[ch] + 1;
            }
        }
        for (char ch: t) {
            if (M.find(ch) == M.end()) {
                return false;
            } else {
                M[ch] = M[ch] - 1;
            }
        }
        for (auto p: M) {
            if ((p.second) != 0) return false;
        }
        return true;
    }
};
