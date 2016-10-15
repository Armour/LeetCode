class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        if (num.length() == k) return "0";
        while (k--) {
            int cur = 0;
            while (cur != num.length()) {
                if (cur == num.length() - 1) {
                    break;
                }
                if (num[cur] > num[cur + 1]) {
                    break;
                }
                cur++;
            }
            num.erase(cur, 1);
        }
        int zero = 0;
        while (num[zero] == '0') zero++;
        bool not_zero = num.find_first_not_of('0') != string::npos;
        num.erase(0, zero);
        return not_zero? num: "0";
    }
};
