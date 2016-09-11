class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto n : nums)
            mp[n]++;
        vector<int> v;
        v.reserve(mp.size());
        for (auto& p : mp)
            v.push_back(p.second);
        k = v.size()-k;
        std::nth_element(v.begin(), v.begin()+k, v.end());
        int kfreq = v[k];
        vector<int> res;
        for (auto& p : mp)
            if (p.second >= kfreq)
                res.push_back(p.first);
        return res;
    }
};
