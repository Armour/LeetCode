class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        if (nums.size() == 0) {
            if (lower == upper) {
                res.push_back(to_string(lower));
            } else {
                res.push_back(to_string(lower) + "->" + to_string(upper));
            }
            return res;
        }
        long long st = lower;
        for (int i = 0; i < nums.size(); i++) {
            if (st >= nums[i]) {
                st++;
                continue;
            } else {
                if (st == nums[i] - 1) {
                    res.push_back(to_string(st));
                } else {
                    res.push_back(to_string(st) + "->" + to_string(nums[i] - 1));
                }
                st = (long long)nums[i] + 1;
            }
        }
        if (st == (long long)upper) {
            res.push_back(to_string(st));
        } else if (st < (long long)upper) {
            res.push_back(to_string(st) + "->" + to_string(upper));
        }
        return res;
    }
};
