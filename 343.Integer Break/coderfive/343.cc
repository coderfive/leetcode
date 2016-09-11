class Solution {
public:
    int integerBreak(int n) {
        int res = 1, rem;
        if (n == 2) return 1;
        if (n == 3) return 2;
        if ((rem = n % 3) == 1) {
            n -= 4;
            res = 4;
        }
        else if (rem == 2) {
            n -= 2;
            res = 2;
        }
        while (n) {
            res *= 3;
            n -= 3;
        }
        return res;
    }
};
