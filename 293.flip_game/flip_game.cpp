class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        if (s.compare("") == 0) return res;
        for (int i = 0; i < s.length() - 1; i++) {
            char c1 = s[i];
            char c2 = s[i + 1];
            if (c1 == c2 && c1 == '+') {
                res.push_back(s.substr(0, i) + "--" + s.substr(i + 2));
            }
        }
        return res;
    }
};
