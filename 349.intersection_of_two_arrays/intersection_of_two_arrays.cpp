class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s, s2;
        for (auto num : nums1) {
            s.insert(num);
        }
        for (auto num : nums2) {
            if (s.find(num) != s.end())
                s2.insert(num);
        }
        vector<int> res(s2.begin(), s2.end());
        return res;
    }
};
