class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        for (int i = 0, j; i < nums.size();) {
            j = i+1;
            while (j < nums.size() && nums[i] + j-i == nums[j]) j++;
            j--;
            res.push_back(std::to_string(nums[i]));
            if (j != i) {
                res.back() += "->" + std::to_string(nums[j]);
            }
            i = j+1;
        }

        return res;
    }
};
