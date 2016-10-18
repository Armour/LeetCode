class Solution {
public:
    static bool comp(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second < b.second;    
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int, int> m;
       vector<int> res;
       for (int num: nums) {
           m[num]++;
       }
       vector<pair<int, int>> h;
       for (auto p: m) {
           h.push_back(p);
       }
       make_heap(h.begin(), h.end(), comp);
       while (k--) {
           int val = h[0].first;
           pop_heap(h.begin(), h.end(), comp);
           h.pop_back();
           res.push_back(val);
       }
       return res;
    }
};
