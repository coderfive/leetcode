// this is a *stupid* (not simple) problem
class Solution {
public:
    bool isUgly(int n) {
        long long num = n;
        if (num <= 0) return false;
        while (num > 1 && (num & 1) == 0) num >>= 1;
        while (num > 0 && num % 3 == 0) num/=3;
        while (num > 0 && num % 5 == 0) num/=5;
        return num <= 1;
    }
};
