class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> v;
        int res = 1;
        v.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            auto it = lower_bound(v.begin(), v.end(), nums[i]);
            if (it == v.end()) {
                v.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
            res = max(res, (int)v.size());
        }
        return res;
    }
};
