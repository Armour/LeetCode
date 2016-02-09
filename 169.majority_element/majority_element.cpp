class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int voter = nums[0];
        int count = 1;

        int size = nums.size();
        for (int i = 1; i< size; i++) {
            if (count == 0) {
                count++;
                voter = nums[i];
            } else if (voter == nums[i])
                count++;
            else
                count--;
        }
        return voter;
    }
};
