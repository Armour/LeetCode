class Solution {
public:
    string updateStr(string str) {
        if (str[str.length() - 1] < '0' || str[str.length() - 1] > '9') return str + "1";
        int i = str.length() - 1;
        while (i >= 0 && (str[i] >= '0' && str[i] <= '9')) {
            i--;
        }
        int val = stoi(str.substr(i + 1));
        string pre = str.substr(0, i + 1);
        pre += to_string(++val);
        return pre;
    }

    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        if (word.length() == 0) {
            res.push_back("");
            return res;
        }
        res.push_back("1");
        res.push_back(word.substr(0, 1));
        for (int i = 1; i < word.length(); i++) {
            vector<string> tmp;
            for (auto str: res) {
                tmp.push_back(str + word[i]);
                tmp.push_back(updateStr(str));
            }
            res = tmp;
        }
        return res;
    }
};
