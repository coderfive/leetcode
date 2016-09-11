class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sz = nums.size();
        int res = (sz+1)*sz / 2;
        for (auto n : nums)
            res -= n;
        return res;
    }
};
