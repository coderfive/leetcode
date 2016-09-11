// runtime: 28 ms
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T> ostream& operator<<(ostream& out, vector<T>& v) {
  if (v.size() == 0) {
    out << "{}";
    return out;
  }
  out << "{" << v[0];
  for (typename::vector<T>::size_type i = 1; i < v.size(); i++)
    out << ", " << v[i];
  out << "}";

  return out;
}

class Solution {
    // [first, last)
    bool is_palind (int first, int last, string& s) {
        last--;
        while (first < last && s[first] == s[last]) {
            first++;
            last--;
        }
        return first >= last;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<int> v;
        v.reserve(s.size()+2);
        vector<vector<string>> res;
        vector<string> tmp;
        v.push_back(0);
        int sz = s.size();
        while (true) {
            if (v.back() < s.size()) {
                v.push_back(v.back()+1);
                tmp.push_back (s.substr(v[v.size()-2], v[v.size()-1]-v[v.size()-2]));
            }
            if (v.back() == sz) {
                res.push_back(tmp);
                while (v.size() > 1) {
                    v.back()++;
                    if (v.back() > s.size()) {
                        tmp.pop_back();
                        v.pop_back();
                    }
                    else {
                        tmp.back().push_back(s[v.back()-1]);
                        if (is_palind(v[v.size()-2], v.back(), s)) break;
                    }
                }
            }
            if (v.size() <= 1) break;
        }

        return res;
    }
};

int main() {
    auto v = Solution().partition(std::string("amanaplanacanalpanama"));
    std::cout << v << std::endl;

    return 0;
}
