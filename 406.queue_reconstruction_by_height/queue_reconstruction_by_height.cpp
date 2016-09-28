class Solution {
public:
    static bool comp(pair<int, int> &p1, pair<int, int> &p2) {
        if (p1.first == p2.first)
            return p1.second < p2.second;
        else 
            return p1.first > p2.first; 
    }

    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> res;
        sort(people.begin(), people.end(), comp);  
        for (int i = 0; i < people.size(); i++) {
            res.insert(res.begin() + people[i].second, people[i]);
        }
        return res;
    }
};
