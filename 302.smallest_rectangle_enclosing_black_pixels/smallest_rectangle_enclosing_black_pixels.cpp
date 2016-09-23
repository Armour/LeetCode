class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        if (image.size() == 0 || image[0].size() == 0) return 0;
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        int minX = image.size();
        int maxX = -1;
        int minY = image[0].size();
        int maxY = -1;
        queue<pair<int, int>> Q;
        set<pair<int, int>> S;
        Q.push(make_pair(x, y));
        S.insert(make_pair(x, y));
        while (!Q.empty()) {
            pair<int, int> cur = Q.front();
            Q.pop();
            minX = min(minX, cur.first);
            maxX = max(maxX, cur.first);
            minY = min(minY, cur.second);
            maxY = max(maxY, cur.second);
            for (int i = 0; i < 4; i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if (nx < 0 || nx >= image.size()) continue;
                if (ny < 0 || ny >= image[0].size()) continue;
                if (image[nx][ny] == '0') continue;
                if (S.find(make_pair(nx, ny)) != S.end()) continue;
                Q.push(make_pair(nx, ny));
                S.insert(make_pair(nx, ny));
            }
        }
        return (maxX - minX + 1) * (maxY - minY + 1);
    }
};
