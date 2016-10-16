class NumMatrix {
public:
    vector<vector<int>> mat;
    vector<vector<int>> sum;

    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        mat = vector<vector<int>> (matrix.size(), vector<int>(matrix[0].size(), 0));
        sum = vector<vector<int>> (matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                update(i, j, matrix[i][j]);
            }
        }
    }

    void update(int row, int col, int val) {
        int before = mat[row][col];
        int dist = val - before;
        if (dist == 0) return;
        int r = row + 1;
        while (r <= mat.size()) {
            int c = col + 1;
            while (c <= mat[0].size()) {
                sum[r][c] += dist;
                c += c & -c;
            }
            r += r & -r;
        }
        mat[row][col] = val;
    }
    
    int get_sum(int row, int col) {
        if (row < 0 || col < 0) return 0;
        int res = 0;
        int r = row + 1;
        while (r > 0) {
            int c = col + 1;
            while (c > 0) {
                res += sum[r][c];
                c -= c & -c;
            }
            r -= r & -r;
        }
        return res;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum1 = get_sum(row2, col2);
        int sum2 = get_sum(row1 - 1, col2);
        int sum3 = get_sum(row2, col1 - 1);
        int sum4 = get_sum(row1 - 1, col1 - 1);
        return sum1 - sum2 -sum3 + sum4;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);
