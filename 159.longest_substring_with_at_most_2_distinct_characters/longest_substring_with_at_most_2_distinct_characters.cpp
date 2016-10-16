class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.compare("") == 0) return 0;
        int st = 0;
        int ed = 0;
        int res = 0;
        unordered_set<char> used;
        unordered_map<char, int> pos;
        for (int i = 0; i < s.length(); i++) {
            if (used.find(s[i]) == used.end()) {
                if (used.size() == 2) {
                    while (pos[s[st]] != st) st++;
                    used.erase(s[st]);
                    pos.erase(s[st]);
                    st++;
                }
                used.insert(s[i]);
            }
            ed = i;
            pos[s[i]] = i;
            res = max(res, ed - st + 1);
        }
        return res;
    }
};
