class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> res;
        for (int n: nums) {
            if (res.find(n) == res.end()) {
                res.insert(n);
            } else
                return true;
        }
        return false;
    }
};
