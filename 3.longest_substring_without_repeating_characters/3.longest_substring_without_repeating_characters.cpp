class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int head = 1;
        int tail = 0;
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (map.find(s[i]) != map.end() && map.find(s[i])->second >= head) {
                head = map.find(s[i])->second + 1;
            }
            tail++;
            map[s[i]] = tail;
            ans = max(ans, tail - head + 1);
        }
        return ans;
    }
};
