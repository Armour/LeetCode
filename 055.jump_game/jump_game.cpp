class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0) return true;
        int maxe = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (i <= maxe) {
                maxe = max(maxe, nums[i] + i);
            } else {
                return false;
            }
        }
        return true;
    }
};
