class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor2 = 0;
        for (auto n : nums)
            xor2 ^= n;
        int xor1 = 0;
        int bit = xor2 - (xor2 & (xor2-1));
        for (auto n : nums)
            if (n & bit) xor1 ^= n;
        vector<int> res;
        res.push_back(xor1);
        res.push_back(xor1^xor2);
        return res;
    }
};
