class Solution {
public:
    void reverseRange(string &s, int st, int ed) {
        for (int i = st, j = ed ; i < j; i++ , j--) {
            swap(s[i], s[j]);
        }
    }

    void reverseWords(string &s) {
        if (s.compare("") == 0) return;

        size_t trimSt = s.find_first_not_of(' ');
        if (trimSt != string::npos)
            s.erase(s.begin(), s.begin() + trimSt);

        size_t trimEd = s.find_last_not_of(' ');
        if (trimSt != string::npos)
            s.erase(s.begin() + trimEd + 1, s.end());

        size_t pos;
        while ((pos = s.find("  ")) != string::npos) {
            s.replace(pos, 2, " ");
        }

        if (s.compare(" ") == 0) {
            s = "";
            return;
        }

        int len = s.length();
        reverseRange(s, 0, len - 1);

        int st = 0;
        int ed = 0;
        while (ed < len) {
            if (s[ed] == ' ') {
                reverseRange(s, st, ed - 1);
                ed++;
                st = ed;
            } else {
                ed++;
            }
        }
        reverseRange(s, st, ed - 1);
    }
};
