class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        vector<vector<bool>> used(grid.size(), vector<bool>(grid[0].size(), false));
        vector<int> movex = {1, -1, 0, 0};
        vector<int> movey = {0, 0, -1, 1};
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1' && !used[i][j]) {
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    used[i][j] = true;
                    while (!q.empty()) {
                        auto p = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int x = p.first + movex[k];
                            int y = p.second + movey[k];
                            if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) continue;
                            if (grid[x][y] != '1') continue;
                            if (used[x][y]) continue;
                            used[x][y] = true;
                            q.push(make_pair(x, y));
                        }
                    }
                    res++;
                } 
            }
        }
        return res;
    }
};
