class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        int st = 0;
        int ed = len - 1;
        while (st < ed) {
            while (st < len && !isalnum(s[st])) st++;
            while (ed >= 0 && !isalnum(s[ed])) ed--;
            if (st >= ed) break;
            if (tolower(s[st]) != tolower(s[ed]))
                return false;
            st++;
            ed--;
        }
        return true;
    }
};
