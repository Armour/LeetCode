class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int i = 0, j = 0;
        int carry = 0;
        while (i < a.length() || j < b.length() || carry) {
            if (i < a.length()) {
                carry += a[i] - '0';
                i++;
            }
            if (j < b.length()) {
                carry += b[j] - '0';
                j++;
            }
            res += to_string(carry % 2);
            carry /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
