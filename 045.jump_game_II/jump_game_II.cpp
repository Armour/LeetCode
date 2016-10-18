class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dist(nums.size(), 0);
        int st = 0;
        int ed = 0;
        for (int i = 0; i < nums.size(); i++) {
            ed = max(ed, min(nums[i] + i, (int)nums.size() - 1));
            for (int j = ed; j > st; j--) {
                dist[j] = dist[i] + 1;
            }
            st = ed;
        }
        return dist[nums.size() - 1];
    }
};
