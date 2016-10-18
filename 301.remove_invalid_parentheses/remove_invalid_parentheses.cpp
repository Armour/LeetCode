class Solution {
public:
    bool valid(string s) {
        int left = 0;
        int right = 0;
        for (char c: s) {
            if (c == '(') {
                left++;
            } else if (c == ')') {
                if (left) {
                    left--;
                } else {
                    return false;
                }
            }
        }
        return left == 0;
    }

    void search(string s, int pos, int left, int right, unordered_set<string> &res) {
        if (left == 0 && right == 0) {
            if (valid(s))
                res.insert(s);
            return;
        }
        for (int i = pos; i < s.size(); i++) {
            if (s[i] == '(') {
                string tmps = s;
                if (right == 0 && left > 0) {
                    tmps.erase(i, 1);
                    search(tmps, i, left - 1, right, res);
                }
            } else if (s[i] == ')') {
                string tmps = s;
                if (right > 0) {
                    tmps.erase(i, 1);
                    search(tmps, i, left, right - 1, res);
                }
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> res;
        if (s.compare("") == 0) {
            vector<string> ret;
            ret.push_back("");
            return ret;
        }
        int left = 0;
        int right = 0;
        for (char c: s) {
            if (c == '(') {
                left++;
            } else if (c == ')') {
                if (left) {
                    left--;
                } else {
                    right++;
                }
            }
        }
        search(s, 0, left, right, res);
        vector<string> ret;
        for (auto r: res) {
            ret.push_back(r);
        }
        return ret;
    }
};
