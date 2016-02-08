class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if (strs.size() == 0) return ans;
        char ch;
        int i = 0;
        while (true) {
            if (strs[0].length() <= i) {
                return ans;
            } else {
                ch = strs[0][i];
            }
            for (string str: strs)
                if (str.length() <= i || str[i] != ch)
                    return ans;
            i++;
            ans += ch;
        }
        return ans;
    }
};
