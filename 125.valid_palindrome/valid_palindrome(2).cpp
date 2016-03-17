class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(), [](int i){return !isalnum(i);}), s.end());
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string s_inv = s;
        reverse(s_inv.begin(), s_inv.end());
        return s.compare(s_inv) == 0;
    }
};
