class Solution {
public:
    char findTheDifference(string s, string t) {
        string c = s + t;
		int result = 0;
		for (int i = 0; i < c.length(); i++) {
			result ^= (int)c[i];
		}
		return (char)result;
    }
};
