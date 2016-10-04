class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for (auto ch: s) {
            m[ch]++;
        }
        int res = 0;
        int odd = 0;
        for (auto p: m) {
            if (p.second % 2 != 0) odd++;
            res += p.second - p.second % 2; 
        }
        if (odd) res++;
        return res;
    }
};
