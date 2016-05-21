
class NumMatrix {
    vector<vector<int>>& mat;
public:
    NumMatrix(vector<vector<int>> &matrix) : mat(matrix) {
        int rows = mat.size();
        if (rows == 0) return;
        int cols = mat[0].size();
        if (cols == 0) return;
        auto& first_row = mat[0];
        for (int i = 1; i < cols; i++)
            first_row[i] += first_row[i-1];
        for (int i = 1; i < rows; i++)
            mat[i][0] += mat[i-1][0];
        for (int r = 1; r < rows; r++)
            for (int c = 1; c < cols; c++)
                mat[r][c] += mat[r-1][c]+mat[r][c-1]-mat[r-1][c-1];
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = mat[row2][col2];
        if (col1) {
            res -= mat[row2][col1-1];
            if (row1) res += mat[row1-1][col1-1];
        }
        if (row1)
            res -= mat[row1-1][col2];
        return res;
    }
};
