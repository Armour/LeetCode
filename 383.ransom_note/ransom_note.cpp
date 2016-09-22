class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        for (char c: magazine) {
            m[c]++;
        }
        for (char c: ransomNote) {
            if (m.find(c) != m.end() && m[c]) {
                m[c]--;
            } else {
                return false;
            }
        }
        return true;
    }
};
