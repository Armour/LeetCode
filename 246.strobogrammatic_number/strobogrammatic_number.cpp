class Solution {
public:
    bool isStrobogrammatic(string num) {
        set<char> s = {'2', '3', '4', '5', '7'};
        for (auto n: num) {
            if (s.find(n) != s.end()) return false;
        }
        string tmp = num;
        reverse(tmp.begin(), tmp.end());
        for (int i = 0; i < num.length(); i++) {
            if (tmp[i] == '6') tmp[i] = '9';
            else if (tmp[i] == '9') tmp[i] = '6';
            if (num[i] != tmp[i]) return false;   
        }
        return true;
    }
};
