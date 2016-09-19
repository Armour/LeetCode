class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (char ch: s) {
            res *= 26;
            res += (int)ch - (int)'A' + 1;
        }   
        return res;
    }
};
