class Solution {
public:
    int maximumGap(vector<int>& nums) {
        std::sort (nums.begin(), nums.end());
        int res = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (res < nums[i] - nums[i-1]) res = nums[i] - nums[i-1];
        }
        return res;
    }
};
