class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int columns = dungeon[0].size(), rows = dungeon.size();
        int minv = dungeon[0][0];
        int sum = 0;
        for (int r = 0; r < rows; r++) {
            sum += dungeon[r][0];
            if (sum < minv) minv = sum;
        }
        for (int c = 1; c < columns; c++) {
            sum += dungeon[rows-1][c];
            if (sum < minv) minv = sum;
        }
        minv = 1-minv;
        int low = 1, high = minv, mid, health, tmp;
        int nfail;
        if (dungeon[0][0] <= 0) low = 1-dungeon[0][0];

        vector<int> arow(columns);
        while (low < high) {
            mid = (low+high)/2;
            arow[0] = dungeon[0][0]+mid;
            for (int c = 1; c < columns; c++) {
                arow[c] = arow[c-1]+dungeon[0][c];
                if (arow[c] <= 0) {
                    std::fill (arow.begin()+c+1, arow.end(), -1);
                    break;
                }
            }
            for (int r = 1; r < rows; r++) {
                nfail = 0;
                if (arow[0] <= 0) {
                    nfail++;
                }
                else {
                    arow[0] += dungeon[r][0];
                    if (arow[0] <= 0) nfail++;
                }
                for (int c = 1; c < columns; c++) {
                    if (arow[c] < arow[c-1]) arow[c] = arow[c-1];
                    if (arow[c] > 0) arow[c] += dungeon[r][c];
                    if (arow[c] <= 0) nfail++;
                }
                if (nfail == columns) break;
            }
            if (arow.back() <= 0) {
                low = mid+1;
            }
            else {
                high = mid;
            }
        }
        return low;
    }
};
