class Solution {
public:
    int numSquares(int n) {
        int t, t2;
        int sq = std::sqrt(n);
        if (sq*sq == n) return 1;
        for (; n-sq*sq <= sq*sq; sq--) {
            t = n-sq*sq;
            t2 = std::sqrt(t);
            if (t2*t2 == t) return 2;
        }
        t = n;
        while (!(t&3)) t >>= 2;
        if (t % 8 != 7) return 3;
        return 4;
    }
};
