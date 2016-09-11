class Solution {
public:
    bool isPowerOfThree(int n) {
        int max_3power = 1162261467; // 3**19
        return n > 0 && (max_3power % n == 0);
    }
};
