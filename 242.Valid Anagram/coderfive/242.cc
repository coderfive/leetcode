class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int n[130];
        std::fill_n (n, 130, 0);
        for (auto c : s)
            n[c]++;
        for (auto c : t)
            if (--n[c] < 0) return false;
        return true;
    }
};
