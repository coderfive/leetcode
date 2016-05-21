class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt = 0;
        vector<int> res;
        if (nums.size() == 0) return res;
        int sz = nums.size(), sz1 = sz/3, sz2 = sz/3*2+1;
        nth_element(nums.begin(), nums.begin()+sz1, nums.end());
        int v1 = nums[sz1];
        cnt = std::count (nums.begin(), nums.end(), v1);
        if (cnt > sz1) res.push_back(v1);
        if (sz2 < sz) {
            nth_element(nums.begin()+sz1+1, nums.begin()+sz2, nums.end());
            cnt = std::count (nums.begin(), nums.end(), nums[sz2]);
            if (cnt > sz1) res.push_back(nums[sz2]);
            if (res.size() == 2 && res[0] == res[1]) res.pop_back();
        }

        return res;
    }
};
