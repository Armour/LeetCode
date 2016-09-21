class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        vector<int> res;
        for (auto num : nums1) {
            m[num]++;
        }
        for (auto num : nums2) {
            if (m.find(num) != m.end() && m[num]) {
                res.push_back(num);
                m[num]--;
            }
        }
        return res;
    }
};
