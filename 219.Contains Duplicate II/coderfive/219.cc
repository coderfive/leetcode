class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_set<int> s;
        if (k <= 0) return false;
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) return true;
            s.insert(nums[i]);
            if (s.size() == k+1) s.erase(nums[i-k]);
        }
        return false;
    }
};
