/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool comp(const Interval &a, const Interval &b) {
        if (a.start < b.start) return true;
        if (a.start > b.start) return false;
        return a.end < b.end;
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() == 0) return intervals;
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), comp);
        int st = intervals[0].start;
        int ed = intervals[0].start;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i].start >= st && intervals[i].start <= ed) {
                ed = max(ed, intervals[i].end);
            } else {
                Interval tmp_interval(st, ed);
                res.push_back(tmp_interval);
                st = intervals[i].start;
                ed = intervals[i].end;
            }
        }
        ed = max(ed, intervals[intervals.size() - 1].end);
        Interval tmp_interval(st, ed);
        res.push_back(tmp_interval);
        return res;
    }
};
