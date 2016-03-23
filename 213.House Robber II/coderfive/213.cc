class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        int with[2], without[2];
        with[0] = nums[0];
        with[1] = 0;
        without[0] = without[1] = 0;
        for (int i = 1; i < nums.size(); i++) {
            int t = with[0];
            with[0] = std::max (with[0], with[1]+nums[i]);
            with[1] = std::max (with[1], t);
            t = without[0];
            without[0] = std::max (without[0], without[1]+nums[i]);
            without[1] = std::max (without[1], t);
        }
        return std::max (with[1], std::max(without[0], without[1]));
    }
};
