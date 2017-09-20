class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int pos = 0;
        unordered_map<int, int> m;
        vector<int> res;
        for (int num: nums) {
            if (m.find(target - num) != m.end()) {
                res.push_back(m[target - num]));
                res.push_back(pos));
                break;
            } else {
                m[num] = pos;
            }
            pos++;
        }
        return res;
    }
};
