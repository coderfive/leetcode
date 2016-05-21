class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, int> mp;
        vector<vector<string>> res;
        vector<int> v(26);
        for (auto& s : strs) {
            std::fill (v.begin(), v.end(), 0);
            for (auto c : s)
                v[c-'a']++;
            auto it = mp.find(v);
            if (it == mp.end()) {
                res.resize(res.size()+1);
                res.back().push_back(s);
                mp[v] = res.size()-1;
            }
            else {
                res[it->second].push_back(s);
            }
        }
        for (auto& vs : res)
            std::sort (vs.begin(), vs.end());

        return res;
    }
};
