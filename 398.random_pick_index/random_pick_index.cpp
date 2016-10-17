class Solution {
public:
    vector<int> _nums;
    
    Solution(vector<int> nums) {
        _nums = nums;
    }
    
    int pick(int target) {
        int res = -1;
        int cnt = 1;
        for (int i = 0; i < _nums.size(); i++) {
            if (_nums[i] == target) {
                if (rand() % (cnt++) == 0)
                    res = i;
            }
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
