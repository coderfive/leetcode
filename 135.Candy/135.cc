class Solution {
public:
    int candy(vector<int>& ratings) {
        int i = 0, sz = ratings.size();
        vector<int> cd (ratings.size());
        if (sz == 0) return 0;
        while (i < sz) {
            cd[i++]=1;
            while (i < sz && ratings[i] > ratings[i-1]) {
                cd[i] = cd[i-1]+1;
                i++;
            }
            int si = i-1;
            while (i < sz && ratings[i] < ratings[i-1]) {
                i++;
            }
            int j = i-1;
            if (j != si) cd[j--] = 1;
            while (j > si) {
                cd[j] = cd[j+1]+1;
                j--;
            }
            if (i-1 != si) {
                if (cd[si] <= cd[si+1]) cd[si] = cd[si+1]+1;
                i--;
            }
        }

        return std::accumulate(cd.begin(), cd.end(), 0);
    }
};
