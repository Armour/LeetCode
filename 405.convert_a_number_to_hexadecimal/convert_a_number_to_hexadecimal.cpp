class Solution {
public:
    string toHex(int num) {
        unsigned int n = num;
        if (!n) return "0";
        string res;
        while (n) {
            int ms = n & 15;
            if (ms < 10)
                res.push_back('0' + ms);
            else
                res.push_back('a' + ms - 10);
            n >>= 4;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
