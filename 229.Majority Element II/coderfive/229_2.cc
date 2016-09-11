class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int v1 = 0, v2 = 0;
        vector<int> res;
        if (nums.size() == 0) return res;
        int sz = nums.size();
        for (auto n : nums) {
            if (v1 == n) {
                cnt1++;
            }
            else if (v2 == n) {
                cnt2++;
            }
            else if (cnt1 == 0) {
                v1 = n;
                cnt1 = 1;
            }
            else if (cnt2 == 0) {
                v2 = n;
                cnt2 = 1;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        if (std::count(nums.begin(), nums.end(), v1) > sz/3) res.push_back(v1);
        if (v1 != v2 && std::count(nums.begin(), nums.end(), v2) > sz/3) res.push_back(v2);

        return res;
    }
};
