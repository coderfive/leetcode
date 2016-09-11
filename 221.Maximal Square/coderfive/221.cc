class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
	int row = matrix.size();
	if (row == 0) return 0;
	int col = matrix[0].size();
	vector<vector<int>> vv (row, vector<int>(col));
	for (int i = 0; i < col; i++)
	    vv[0][i] = matrix[0][i] - '0';
	auto relax = [&] (int r, int c) {
	    if (matrix[r][c] == '1')
		vv[r][c] = std::min(std::min(vv[r-1][c], vv[r][c-1]), vv[r-1][c-1]) + 1;
	    else
		vv[r][c] = 0;
	};
	for (int i = 1; i < row; i++) {
	    vv[i][0] = matrix[i][0] - '0';
	    for (int j = 1; j < col; j++)
		relax (i, j);
	}
	int res = 0;
	for (auto& v : vv) {
	    auto n = *std::max_element(v.begin(), v.end());
	    if (n > res) res = n;
	}

	return res*res;
    }
};
