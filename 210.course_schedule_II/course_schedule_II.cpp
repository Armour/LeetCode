class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        if (numCourses == 0) return res;
        vector<int> g[numCourses];
        vector<int> degree(numCourses, 0);
        for (auto pre: prerequisites) {
            g[pre.second].push_back(pre.first);
            degree[pre.first]++;
        }
        int cnt = 0;
        queue<int> q;
        for (int i = 0; i < degree.size(); i++) {
            if (degree[i] == 0) {
                q.push(i);
                cnt++;
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            res.push_back(cur);
            for (auto e: g[cur]) {
                if (--degree[e] == 0) {
                    q.push(e);
                    cnt++;
                }
            }
        }
        if (cnt != numCourses) {
            res.clear();
        }
        return res;
    }
};

