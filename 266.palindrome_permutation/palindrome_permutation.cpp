class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char, int> m;
        for (char ch: s) {
            m[ch]++;
        }
        int flag = 0;
        for (pair<char, int> i: m) {
            if (i.second % 2 != 0) flag++;
        }
        return flag <= 1;
    }
};
