class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s (nums1.begin(), nums1.end());
        vector<int> res;
        auto it = s.end();
        for (auto n : nums2) {
            if ((it = s.find(n)) != s.end()) {
                res.push_back(n);
                s.erase(it);
            }
        }

        return res;
    }
};
