class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        if (nums.size() == 0) return res; 
        auto st = lower_bound(nums.begin(), nums.end(), target);
        auto ed = upper_bound(nums.begin(), nums.end(), target);
        if (st == nums.end() || *st != target) {
            return res;
        } else {
            res[0] = st - nums.begin();
            if (ed == nums.end()) {
                res[1] = nums.size() - 1;
            } else {
                res[1] = ed - nums.begin() - 1;
            }
        }
        return res;
    }
};
