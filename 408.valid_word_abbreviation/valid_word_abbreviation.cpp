class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int idx1 = 0;
        int idx2 = 0;
        while (idx1 < word.length() && idx2 < abbr.length()) {
            if (abbr[idx2] == '0') return false;
            if (abbr[idx2] >= '1' && abbr[idx2] <= '9') {
                int num = 0;
                while (idx2 < abbr.length() && abbr[idx2] >= '0' && abbr[idx2] <= '9') {
                    num *= 10;
                    num += (int)(abbr[idx2++] - '0');
                }
                idx1 += num;
            } else {
                if (word[idx1++] != abbr[idx2++])
                    return false;
            }
        }
        return idx1 == word.length() && idx2 == abbr.length();
    }
};
