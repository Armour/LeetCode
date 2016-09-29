class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() <= 1) return;
        for (int i = 1; i < nums.size(); i++) {
            if (i % 2 == 0) {
                if (nums[i] > nums[i - 1])
                    swap(nums[i], nums[i - 1]);
            } else {
                if (nums[i] < nums[i - 1])
                    swap(nums[i], nums[i - 1]);
            }
        }
    }
};
