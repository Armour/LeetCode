class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long max1 = LONG_MIN;
        long long max2 = LONG_MIN;
        long long max3 = LONG_MIN;
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        for (int i = 0; i < nums.size(); i++) {
            if ((long long)nums[i] > max1) {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            } else if ((long long)nums[i] > max2 && (long long)nums[i] != max1) {
                max3 = max2;
                max2 = nums[i];
            } else if ((long long)nums[i] > max3 && (long long)nums[i] != max1 && (long long)nums[i] != max2) {
                max3 = nums[i];
            }
        }
        return max3 != LONG_MIN? max3: max1;
    }
};
