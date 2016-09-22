class Solution {
public:
    void search(int val, int curLight, int maxLight, int depth, int maxDepth, set<string> &res) {
        if (depth > maxDepth) return;
        if (curLight == maxLight) res.insert(to_string(val));
        search(val, curLight, maxLight, depth + 1, maxDepth, res);
        search(val | 1 << depth, curLight + 1, maxLight, depth + 1, maxDepth, res);
    }

    set<string> getStrings(int maxLight, int maxDigits) {
        set<string> res;
        search(0, 0, maxLight, 0, maxDigits, res);
        return res;
    }

    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        if (num < 0) return res;
        if (num == 0) {
            res.push_back("0:00");
            return res;
        }
        if (num > 10) num = 10;
        for (int i = 0; i <= min(num, 4); i++) {
            int top = i;
            int bot = num - i;
            set<string> tops = getStrings(top, 4);
            set<string> bots = getStrings(bot, 6);
            for (auto t: tops) {
                if (stoi(t) > 11) continue;
                for (auto b: bots) {
                    if (stoi(b) > 59) continue;
                    res.push_back(t + ":" + (b.length() == 1? ("0" + b): b));
                }
            }
        }
        return res;
    }
};
