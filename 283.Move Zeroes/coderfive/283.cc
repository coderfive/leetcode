class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int st = 0, i, sz = nums.size();
        while (st < sz && nums[st] != 0) st++;
        i = st+1;
        while (i < sz) {
            if (nums[i] != 0) nums[st++] = nums[i];
            i++;
        }
        if (st < sz) std::fill (nums.begin()+st, nums.end(), 0);
    }
};
