class Solution {
public:
    string getHint(string secret, string guess) {
        if (secret.compare("") == 0) return "0A0B";
        unordered_map<char, int> m1, m2;
        int a = 0;
        int b = 0;
        for (int i = 0; i < secret.length(); i++) {
            if (guess.length() > i) {
                if (secret[i] == guess[i]) {
                    a++;
                } else {
                    m1[secret[i]]++;
                    m2[guess[i]]++;
                }
            }
        }
        for (int i = secret.length(); i < guess.length(); i++) {
            m2[guess[i]]++;
        }
        for (auto p: m1) {
            if (m2.find(p.first) != m2.end()) {
                b += min(p.second, m2[p.first]);
            }
        }
        return to_string(a) + "A" + to_string(b) + "B";
    }
};
