class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        res[0] = nums[0];
        int mul = 1;
        for (int i = 1; i < nums.size(); i++)
            res[i] = res[i-1] * nums[i];
        for (int i = nums.size()-1; i > 0; i--) {
            res[i] = mul*res[i-1];
            mul *= nums[i];
        }
        res[0] = mul;
        return res;
    }
};
