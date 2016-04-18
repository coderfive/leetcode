class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> s;
        for (auto a : nums) {
            if (s.find(a) != s.end()) return true;
            s.insert(a);
        }
        return false;
    }
};
