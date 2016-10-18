class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int res = 0;
        make_heap(nums.begin(), nums.end());
        while (k--) {
            pop_heap(nums.begin(), nums.end());
            res = nums[nums.size() - 1];
            nums.pop_back();
        }
        return res; 
    }
};
