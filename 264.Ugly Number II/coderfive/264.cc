class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v  {0, 1};
        v.reserve(n+1);
        int i2 = 1, i3 = 1, i5 = 1;
        while (v.size() <= n) {
            v.push_back (std::min(v[i2]*2, std::min(v[i3]*3, v[i5]*5)));
            if (v.back() == v[i2]*2) i2++;
            if (v.back() == v[i3]*3) i3++;
            if (v.back() == v[i5]*5) i5++;
        }
        return v[n];
    }
};
