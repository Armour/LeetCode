class Solution {
public:
    string multiply(string num1, string num2) {
        string res(num1.length() + num2.length(), '0');
        for (int i = num1.length() - 1; i >= 0; i--)
            for (int j = num2.length() - 1; j >= 0; j--) {
                int tmp = (int)(num1[i] - '0') * (int)(num2[j] - '0') + (int)(res[i + j + 1] - '0');
                res[i + j + 1] = tmp % 10 + '0';
                res[i + j] += tmp / 10;
            }
        size_t pos = res.find_first_not_of('0');
        if (pos == string::npos) {
            return "0";
        }
        return res.substr(pos);
    }
};
