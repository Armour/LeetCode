class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        if (str.length() <= 1) return false;
        bool res = false;
        for (int i = 1; i <= str.length() / 2; i++) {
            if (str.length() % i != 0) continue;
            int st = 0;
            bool flag = true;
            string s = str.substr(st, i);
            st += i;
            while (st < str.length()) {
                if (s.compare(str.substr(st, i)) != 0) {
                    flag = false;
                    break;
                }
                st += i;
            }
            res |= flag;
            if (res) break;
        }
        return res;
    }
};
