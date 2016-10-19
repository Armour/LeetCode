class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() <= 2) return res;
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < nums.size() - 2) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                i++;
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    vector<int> tmpv = {nums[i], nums[j], nums[k]};
                    res.push_back(tmpv);
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (k > j && nums[k] == nums[k + 1]) k--;
                } else if (sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
            i++;
        }
        return res;
    }
};
