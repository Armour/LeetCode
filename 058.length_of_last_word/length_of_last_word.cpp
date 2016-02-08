class Solution {
public:
    int lengthOfLastWord(string s) {
        size_t p = s.find_last_not_of(" ");
        if (p != string::npos)
            s.erase(p + 1);
        if (s.find(" ") != string::npos) {
            size_t p = s.find_last_of(" ");
            return s.length() - p - 1;
        } else {
            return s.length();
        }
    }
};
