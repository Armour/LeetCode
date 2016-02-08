class Solution {
public:
    int BinaryStrToInt(string &str) {
        if (str.compare("") == 0) return 0;
        int n = 0;
        for (char ch: str) {
            n <<= 1;
            if (ch == '1')
                n += 1;
        }
        return n;
    }

    string IntToBinaryStr(int n) {
        if (n == 0) return "0";
        string ans = "";
        while (n != 0) {
            ans.append(n % 2 == 0? "0" : "1");
            n /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string addBinary(string a, string b) {
        int x = BinaryStrToInt(a);
        int y = BinaryStrToInt(b);
        return IntToBinaryStr(x + y);
    }
};
