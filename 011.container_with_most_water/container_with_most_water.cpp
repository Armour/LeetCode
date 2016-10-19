class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        if (height.size() == 0) return 0;
        int st = 0;
        int ed = height.size() - 1;
        while (st < ed) {
            res = max(res, (ed - st) * min(height[st], height[ed]));
            if (height[st] > height[ed]) {
                ed--;
            } else {
                st++;
            }
        }
        return res;
    }
};
