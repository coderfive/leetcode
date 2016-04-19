class Solution {
    int probe (int r, int c, vector<vector<int>>& matrix, vector<vector<int>>& path_len) {
        if (path_len[r][c] > 0) return path_len[r][c];
        int& res = path_len[r][c];
        res = 1;
        int t;
        if (r > 0 && matrix[r-1][c] > matrix[r][c]) {
            t = probe (r-1, c, matrix, path_len)+1;
            if (t > res) res = t;
        }
        if (r < matrix.size()-1 && matrix[r+1][c] > matrix[r][c]) {
            t = probe (r+1, c, matrix, path_len)+1;
            if (t > res) res = t;
        }
        if (c > 0 && matrix[r][c-1] > matrix[r][c]) {
            t = probe (r, c-1, matrix, path_len)+1;
            if (t > res) res = t;
        }
        if (c < matrix[0].size()-1 && matrix[r][c+1] > matrix[r][c]) {
            t = probe (r, c+1, matrix, path_len)+1;
            if (t > res) res = t;
        }
        return res;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size(), col;
        if (row == 0) return 0;
        col = matrix[0].size();
        vector<vector<int>> path_len (row, vector<int>(col, 0));
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                probe(i, j, matrix, path_len);
        int res = 1, t;
        for (auto& v : path_len) {
            t = *std::max_element (v.begin(), v.end());
            if (t > res) res = t;
        }
        return res;
    }
};
