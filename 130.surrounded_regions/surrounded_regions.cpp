class Solution {
public:
    vector<int> mx = {0, 0, -1, 1};
    vector<int> my = {1, -1, 0, 0};

    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) return;
        queue<pair<int, int>> q;
        for (int i = 0; i < board.size(); i++) {
            if (board[i][0] == 'O') q.push(make_pair(i, 0));
            if (board[i][board[0].size() - 1] == 'O') q.push(make_pair(i, board[0].size() - 1));
        }
        for (int j = 0; j < board[0].size(); j++) {
            if (board[0][j] == 'O') q.push(make_pair(0, j));
            if (board[board.size() - 1][j] == 'O') q.push(make_pair(board.size() - 1, j));
        }        
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            if (board[x][y] != 'O') continue;
            board[x][y] = 'E';
            for (int i = 0; i < mx.size(); i++) {
                int nx = x + mx[i];
                int ny = y + my[i];
                if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size()) continue;
                if (board[nx][ny] != 'O') continue;
                q.push(make_pair(nx, ny));
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'E')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};
