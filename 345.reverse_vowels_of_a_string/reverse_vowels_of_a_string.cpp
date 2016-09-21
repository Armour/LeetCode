class Solution {
public:
    string reverseVowels(string s) {
        set<char> v = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for (int i = 0, j = s.length() - 1; i < j;) {
            bool find1 = v.find(s[i]) != v.end();
            bool find2 = v.find(s[j]) != v.end();
            if (find1 && find2) {
                swap(s[i++], s[j--]);
            } else if (find1) {
                j--;
            } else {
                i++;
            }
        }
        return s;
    }
};
