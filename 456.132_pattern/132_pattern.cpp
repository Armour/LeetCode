class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) return false;
        vector<int> mins;
        int tmp = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            tmp = min(tmp, nums[i]);
            mins.push_back(tmp);
        }
        set<int> s;
        s.insert(nums[nums.size() - 1]);
        for (int i = nums.size() - 2; i >= 1; i--) {
            int mint = mins[i - 1];
            int maxt = nums[i];
            auto it = s.upper_bound(mint);
            if (it != s.end() && (*it) < maxt) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};
