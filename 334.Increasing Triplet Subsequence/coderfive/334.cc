class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min_value, mid_value, i = 1, sz = nums.size();
        while (i < sz && nums[i] <= nums[i-1]) i++;
        if (i >= sz) return false;
        min_value = nums[i-1];
        mid_value = nums[i];
        while (++i < sz) {
            if (nums[i] < min_value) {
                min_value = nums[i];
            }
            else if (nums[i] > mid_value) return true;
            else if (nums[i] > min_value && nums[i] < mid_value)
                mid_value = nums[i];
        }

        return false;
    }
};
