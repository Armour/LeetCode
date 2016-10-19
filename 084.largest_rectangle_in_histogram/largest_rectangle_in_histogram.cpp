class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> s;
        int res = 0;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++) {
            while (!s.empty() && heights[s.back()] >= heights[i]) {
                if (s.size() == 1) {
                    res = max(res, heights[s.back()] * i);
                } else {
                    res = max(res, heights[s.back()] * (i - s[s.size() - 2] - 1));
                }
                s.pop_back();
            }
            if (s.empty()) {
                res = max(res, heights[i] * (i + 1));
            }
            s.push_back(i);
        }
        return res;
    }
};
