class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int pos = 0;
        map<int, int> m;
        vector<int> res;
        for (auto num: nums) {
            if (m.find(target - num) != m.end()) {
                res.push_back(min(m[target - num], pos));
                res.push_back(max(m[target - num], pos));
                break;
            } else {
                m[num] = pos;
            }
            pos++;
        }
        return res;
    }
};
