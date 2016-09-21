class ValidWordAbbr {
public:
    unordered_map<string, int> m;
    set<string> s;

    ValidWordAbbr(vector<string> &dictionary) {
        for (string str: dictionary) {
            if (s.find(str) == s.end()) {
                s.insert(str);
                if (str.length() >= 3) {
                    str = str[0] + to_string(str.length() - 2) + str[str.length() - 1];
                }
                m[str]++;
            }
        }
    }

    bool isUnique(string word) {
        string str = word;
        if (str.length() >= 3) {
            str = str[0] + to_string(str.length() - 2) + str[str.length() - 1];
        }
        return m.find(str) == m.end() || s.find(word) != s.end() && m[str] == 1;
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
