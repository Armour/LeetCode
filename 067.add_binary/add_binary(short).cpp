class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        while (i >= 0 || j >= 0 || carry == 1) {
            int ai = i >= 0? a[i--] - '0': 0;
            int bj = j >= 0? b[j--] - '0': 0;
            int val = (ai + bj + carry) % 2;
            carry = (ai + bj + carry) / 2;
            result = (val > 0? '1': '0') + result;
        }
        return result;
    }
};
