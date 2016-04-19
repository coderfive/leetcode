#include <iostream>

class Solution {
public:
    int countDigitOne(int n) {
        int res = 0, all = 0, ten_pow = 1, rem = 0;
        int t;
        if (n <= 0) return 0;
        while (n) {
            t = n%10;
            n /= 10;
            if (t > 1) {
                res += t * all + ten_pow;
            }
            else if (t == 1) {
                res += rem+1 + all;
            }
            all = ten_pow + 10 * all;
            rem += t*ten_pow;
            ten_pow *= 10;
        }

        return res;
    }
};

int main() {
    Solution s;
    std::cout.setf (std::iostream::boolalpha);
    std::cout << "n == 1: " << (1 == s.countDigitOne(1)) << std::endl;
    std::cout << "n == 2: " << (1 == s.countDigitOne(2)) << std::endl;
    std::cout << "n == 10: " << (2 == s.countDigitOne(10)) << std::endl;
    std::cout << "n == 11: " << (4 == s.countDigitOne(11)) << std::endl;
    std::cout << "n == 12: " << (5 == s.countDigitOne(12)) << std::endl;
    std::cout << "n == 13: " << (6 == s.countDigitOne(13)) << std::endl;
    std::cout << "n == 20: " << (12 == s.countDigitOne(20)) << std::endl;

    return 0;
}
