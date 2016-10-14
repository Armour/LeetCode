class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int idx1 = num1.size() - 1;
        int idx2 = num2.size() - 1;
        int carry = 0;
        while (idx1 >= 0 || idx2 >= 0 || carry) {
            int cur = carry;
            if (idx1 >= 0) {
                cur += num1[idx1--] - '0';
            }
            if (idx2 >= 0) {
                cur += num2[idx2--] - '0';
            }
            res += to_string(cur % 10);
            carry = cur / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
