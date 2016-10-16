class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.size() == 0) return res;
        int st = nums[0];
        int ed = nums[0] - 1;
        for (int i = 0; i < nums.size(); i++) {
            if (ed + 1 == nums[i]) {
                ed++;
                continue;
            }
            if (st == ed) {
                res.push_back(to_string(st));
            } else {
                res.push_back(to_string(st) + "->" + to_string(ed));
            }
            st = nums[i];
            ed = nums[i];
        }
        if (st == ed) {
            res.push_back(to_string(st));
        } else {
            res.push_back(to_string(st) + "->" + to_string(ed));
        }
        return res;
    }
};
