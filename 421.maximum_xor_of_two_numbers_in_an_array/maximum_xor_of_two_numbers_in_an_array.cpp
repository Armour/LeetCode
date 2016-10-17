class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        int mask = 0;
        for (int i = 30; i >= 0; i--) {
            unordered_set<int> s;
            mask |= 1 << i;
            for (int j = 0; j < nums.size(); j++) {
                int masked_num = nums[j] & mask;
                int expect = (res | 1 << i);
                if (s.find(expect ^ masked_num) != s.end()) {
                    res |= 1 << i;
                    break;
                }
                s.insert(masked_num);
            }
        }
        return res;
    }
};
