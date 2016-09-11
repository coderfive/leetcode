#include <iostream>
#include <string>
using namespace std;

class Solution {
    string tens (int n) {
        static string s[] = {
            "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
            "Eighty", "Ninety"
        };
        return s[n];
    }
    string less_20 (int n) {
        static string s[] = {
            "", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
            "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen",
            "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
            "Nineteen"
        };
        return s[n];
    }
    // n \in [1, 1000)
    string less_1000 (int n) {
        std::string res;
        int d1, d2, d3;
        d1 = n % 10;
        d2 = (n%100) / 10;
        d3 = n/100;
        if (d3) res = less_20(d3) + " Hundred";
        if (d2 >= 2) {
            if (res.size() != 0) res += " ";
            res += tens(d2);
            if (d1)
                res += std::string(" ") + less_20(d1);
        }
        else {
            if ((d1 || d2) && res.size() != 0) res += " ";
            res += less_20 (d2*10 + d1);
        }
        return res;
    }
    string get_space (string& s) {
        if (s.empty()) return std::string();
        return std::string(" ");
    }
public:
    string numberToWords(int num) {
        if (num == 0) return std::string("Zero");
        std::string res;
        auto t = num % 1000;
        num /= 1000;
        if (t) res = less_1000(t);
        t = num % 1000;
        num /= 1000;
        if (t) res = less_1000(t) + " Thousand" + get_space(res) + res;
        t = num % 1000;
        num /= 1000;
        if (t) res = less_1000(t) + " Million" + get_space(res) + res;
        t = num % 1000;
        num /= 1000;
        if (t) res = less_1000(t) + " Billion" + get_space(res) + res;

        return res;
    }
};


int main() {
    Solution s;
    std::cout << "'" << s.numberToWords(123) << "'" << std::endl;
    std::cout << "'" << s.numberToWords(12345) << "'" << std::endl;
    std::cout << "'" << s.numberToWords(1234567) << "'" << std::endl;

    return 0;
}
