class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        if (nums.size() == 0) {
            return res;
        } else {
            multiset<int> s;
            for (int i = nums.size() - 1; i >= 0; i--) {
                auto it = s.lower_bound(nums[i]);
                res.push_back((int)distance(s.begin(), it));
                s.insert(nums[i]);
            }
            reverse(res.begin(), res.end());
        }
        return res;
    }
};
