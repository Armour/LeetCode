class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int cur = 0;
        if (nums.size() == 0) return 0;
        for (int i = 0; i < nums.size(); i++) {
            cur += nums[i];
            res = max(res, cur);
            if (cur < 0) cur = 0;
        }
        return res;
    }
};
