class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) return 0;
        vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));
        int res = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'X' && !used[i][j]) {
                    used[i][j] = true;
                    res++;
                    int ki = i;
                    int kj = j;
                    while (++ki < board.size()) {
                        if (board[ki][j] != 'X') break;
                        used[ki][j] = true;
                    }
                    while (++kj < board[0].size()) {
                        if (board[i][kj] != 'X') break;
                        used[i][kj] = true;
                    }
                }
            }
        }
        return res;
    }
};
