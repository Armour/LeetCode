class Solution {
public:
    string ReadOff(string &s) {
        string tmp = "";
        char prev = '0';
        int counter = 0;
        for (int i = 0; i < s.length(); i++) {
            if (prev == '0' || prev == s[i]) {
                prev = s[i];
                counter++;
            } else {
                tmp += to_string(counter);
                tmp += prev;
                prev = s[i];
                counter = 1;
            }
        }
        tmp += to_string(counter);
        tmp += prev;
        return tmp;
    }

    string countAndSay(int n) {
        string ans = "1";
        if (n == 1) return ans;
        while (n > 1) {
            ans = ReadOff(ans);
            n--;
        }
        return ans;
    }
};
