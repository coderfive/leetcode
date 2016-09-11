class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vs;
        string res;
        for (auto n : nums)
            vs.push_back(to_string(n));
        std::sort (vs.begin(), vs.end(), [] (const string& lhs, const string& rhs) {
                return lhs+rhs > rhs+lhs;
                });
        if (vs[0][0] == '0') return string("0");
        return std::accumulate (vs.begin(), vs.end(), res);
    }
};
