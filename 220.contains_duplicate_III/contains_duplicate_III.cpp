class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> bst;
        for (int i = 0; i < nums.size(); i++) {
            if (i - k > 0) bst.erase(nums[i - k - 1]);
            auto lower = bst.lower_bound(nums[i] - t);
            if (lower != bst.end()) {
                if (abs(*lower - nums[i]) <= t) return true;
            }
            bst.insert(nums[i]);
        }
        return false;
    }
};
