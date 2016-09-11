class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<int> st (128, -1), end (128, -1);
        std::unordered_set<std::string> str_set;
        int s = 0, e;
        for (auto c : pattern) {
            if (s >= str.size()) return false;
            e = s+1;
            while (e < str.size() && str[e] != ' ') e++;
            if (st[c] == -1) {
                st[c] = s;
                end[c] = e;
                if (str_set.find(str.substr(s, e-s)) != str_set.end())
                    return false;
                str_set.insert(str.substr(s, e-s));
            }
            else {
                if (end[c] - st[c] != e-s || !std::equal(str.begin()+s, str.begin()+e, str.begin()+st[c]))
                    return false;
            }
            s = e+1;
        }
        while (s < str.size() && str[s] == ' ') s++;
        if (s < str.size()) return false;

        return true;
    }
};
