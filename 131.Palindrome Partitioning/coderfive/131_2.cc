// runtime: 8 ms.
class Solution {
    bool is_palind (int first, int last, string& s) {
        last--;
        while (first < last && s[first] == s[last]) {
            first++;
            last--;
        }
        return first >= last;
    }
    void push_string (vector<string>& tmp, vector<vector<string>>& res, int i, vector<vector<int>>& v, string& s) {
        if (i == s.size()) {
            res.push_back(tmp);
            return;
        }
        for (int j = 0; j < v[i].size(); j++) {
            tmp.push_back(s.substr(i, v[i][j]));
            push_string(tmp, res, i+v[i][j], v, s);
            tmp.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<vector<int>> v (s.size());
        for (int i = 0; i < v.size(); i++) {
            v[i].push_back(1);
            for (int j = 2; i+j <= s.size(); j++)
                if (is_palind(i, i+j, s))
                    v[i].push_back(j);
        }
        vector<string> tmp;
        push_string (tmp, res, 0, v, s);

        return res;
    }
};
