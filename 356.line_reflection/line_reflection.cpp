class Solution {
public:
    static bool comp1(const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.first < p2.first || p1.first == p2.first && p1.second < p2.second;
    }
    
    static bool comp2(const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.first < p2.first || p1.first == p2.first && p1.second > p2.second;
    }
    
    static bool equal(const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.first == p2.first && p1.second == p2.second;
    }

    bool isReflected(vector<pair<int, int>>& points) {
        if (points.size() <= 1) return true;
        auto it = unique(points.begin(), points.end(), equal);
        points.resize(it - points.begin());
        sort(points.begin(), points.end(), comp1);
        int tmp = points.size() / 2;
        sort(points.begin() + tmp, points.end(), comp2);
        double mid;
        if (points.size() % 2 == 0) {
            mid = points[tmp].first + points[tmp - 1].first;
        } else {
            mid = points[tmp].first * 2;
        }
        for (int i = 0; i < tmp; i++) {
            int j = points.size() - i - 1;
            if (points[i].first + points[j].first != mid || 
                (!(points[i].first == points[j].first) && points[i].second != points[j].second))
                    return false;
        }
        return true;
    }
};
