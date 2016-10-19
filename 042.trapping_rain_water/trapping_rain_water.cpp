class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left;
        vector<int> right;
        stack<int> s;
        int res = 0;
        if (height.size() == 0) return 0;
        for (int i = 0; i < height.size(); i++) {
            if (s.empty() || height[i] > s.top()) {
                s.push(height[i]);
            }
            left.push_back(s.top());
        }
        while (!s.empty()) s.pop();
        for (int i = height.size() - 1; i >= 0 ; i--) {
            if (s.empty() || height[i] > s.top()) {
                s.push(height[i]);
            }
            right.push_back(s.top());
        }
        reverse(right.begin(), right.end());
        for (int i = 0; i < left.size(); i++) {
            res += min(left[i], right[i]) - height[i];
        }
        return res;
    }
};
