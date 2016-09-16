class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int st = 0; 
        int ed = nums.size() - 1;
        int mid = (st + (ed - st) / 2);
        while (st <= ed) {
            if (nums[mid] == target) {
                return mid;
            } else {
                if (nums[mid] < target) {
                    st = mid + 1;
                } else {
                    ed = mid - 1;
                }
                mid = (st + (ed - st) / 2);
            }
        }
        return st;
    }
};
