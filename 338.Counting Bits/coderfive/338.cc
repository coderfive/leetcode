class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);
        int i, sz;
        while (res.size() <= num) {
            sz = res.size();
            i = 0;
            while (i < sz && res.size() <= num) res.push_back (1+res[i++]);
        }
        return res;
    }
};
