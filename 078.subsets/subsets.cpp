class Solution {
public:
    void dfs(int depth, vector<int> &nums, vector<vector<int>> &res, unordered_set<int> &s) {
        if (depth == nums.size()) {
            vector<int> v(s.begin(), s.end());
            res.push_back(v);
            return;
        }
        dfs(depth + 1, nums, res, s);
        s.insert(nums[depth]);
        dfs(depth + 1, nums, res, s);
        s.erase(nums[depth]);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_set<int> s;
        dfs(0, nums, res, s);
        return res;
    }
};
