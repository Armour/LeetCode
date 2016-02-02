class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map;
        vector<int> v;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            int index = it - nums.begin() + 1;
            if (map.find(target - *it) != map.end()) {
                v.push_back(map.find(target - *it)->second);
                v.push_back(index);
            } else {
                map[*it] = index;
            }
        }
        return v;
    }
};
