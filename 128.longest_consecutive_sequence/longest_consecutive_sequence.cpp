class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 1;
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }
        int res = 1;
        int cur; 
        while (!s.empty()) {
            cur = 1;
            int val = *(s.begin());
            s.erase(val);
            int tmp = val;
            while (s.find(++tmp) != s.end()) {
                cur++;
                s.erase(tmp);
            }
            tmp = val;
            while (s.find(--tmp) != s.end()) {
                cur++;
                s.erase(tmp);
            }
            res = max(res, cur);
        }
        return res;
    }
};
