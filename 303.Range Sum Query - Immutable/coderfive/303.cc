
class NumArray {
    vector<int>& v;
    int sz;
public:
    NumArray(vector<int> &nums) : v(nums) {
        sz = 1;
    }

    int sumRange(int i, int j) {
        while (sz <= j) {
            v[sz] += v[sz-1];
            sz++;
        }
        int res = v[j];
        if (i != 0) res -= v[i-1];
        return res;
    }
};
