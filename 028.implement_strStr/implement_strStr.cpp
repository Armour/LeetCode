class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < (int)(haystack.length() - needle.length()) + 1; i++) {
            string tmpstr = haystack.substr(i, needle.length());
            if (tmpstr.compare(needle) == 0) {
                return i;
            }
        }
        return -1;
    }
};

// haystack.find(needle) != string::npos