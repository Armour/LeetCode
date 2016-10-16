class NumMatrix {
public:
    vector<vector<int>> _sum;

    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        _sum = matrix;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (i - 1 >= 0)
                    _sum[i][j] += _sum[i - 1][j];
                if (j - 1 >= 0)
                    _sum[i][j] += _sum[i][j - 1];
                if (i - 1 >= 0 && j - 1 >= 0)
                    _sum[i][j] -=  _sum[i - 1][j - 1]; 
            }
        }
    }
    
    int get_sum(int row, int col) {
        if (row < 0 || col < 0) return 0;
        return _sum[row][col];
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
// numMatrix.sumRegion(1, 2, 3, 4);
