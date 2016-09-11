class Solution {
    bool is_inter (int i1, int i2, string& s1, string& s2, string& s3, vector<vector<int>>& mat) {
        if (mat[i1][i2] != -1) return 1 == mat[i1][i2];
        if (i1 != s1.size()) {
            if (s3[i1+i2] == s1[i1] && is_inter (i1+1, i2, s1, s2, s3, mat)) {
                mat[i1][i2] = 1;
                return true;
            }
        }
        if (i2 != s2.size()) {
            if (s3[i1+i2] == s2[i2] && is_inter (i1, i2+1, s1, s2, s3, mat)) {
                mat[i1][i2] = 1;
                return true;
            }
        }
        mat[i1][i2] = 0;
        return false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<vector<int>> matrix (s1.size()+1, vector<int>(s2.size()+1, -1));
        matrix[s1.size()][s2.size()] = 1;
        return is_inter (0, 0, s1, s2, s3, matrix);
    }
};
