class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        unordered_map<string, int> m;
        for (string str: strings) {
            string tmp = "a";
            int dist = str[0] - 'a';
            for (int i = 1; i < str.size(); i++) {
                char ch = str[i] - dist;
                if (ch < 'a') ch += 26;
                tmp += to_string(ch);
            }
            if (m.find(tmp) == m.end()) {
                vector<string> tmpvs;
                res.push_back(tmpvs);
                m[tmp] = res.size() - 1;
            }
            res[m[tmp]].push_back(str);
        }
        return res;
    }
};
