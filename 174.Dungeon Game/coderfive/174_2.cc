class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size(), columns = dungeon[0].size();
        vector<int> health (columns, std::numeric_limits<int>::max());
        health.back() = 1;
        for (int i = rows-1; i >= 0; i--) {
            int c = columns-1;
            health[c] -= dungeon[i][c];
            if (health[c] < 1) health[c] = 1;
            for (c--; c >= 0; c--) {
                if (health[c] > health[c+1]) health[c] = health[c+1];
                health[c] -= dungeon[i][c];
                if (health[c] < 1) health[c] = 1;
            }
        }

        return health[0];
    }
};
