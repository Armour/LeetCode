class Solution {
public:
    void split(string &str, char delim, vector<string> &strs) {
        stringstream ss(str);
        string st;
        while (getline(ss, st, delim)) {
            strs.push_back(st);
        }
    }

    bool wordPattern(string pattern, string str) {
        if (pattern.compare("") == 0)
            return false;
        if (str.compare("") == 0)
            return false;
        map<char, string> map_cts;
        map<string, char> map_stc;
        vector<string> strs;
        split(str, ' ', strs);
        int i = 0;
        for (char ch : pattern) {
            if (strs.size() < i + 1)
                return false;
            if (map_cts.find(ch) == map_cts.end()) {
                if (map_stc.find(strs[i]) != map_stc.end()) {
                    return false;
                } else {
                    map_cts[ch] = strs[i];
                    map_stc[strs[i]] = ch;
                }
            } else {
                if (map_cts[ch] != strs[i])
                    return false;
            }
            i++;
        }
        return (strs.size() == i);
    }
};
