class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> bitmap (words.size(), 0);
        int max_len = 0;
        for (int i = 0; i < words.size(); i++) {
            if (max_len < words[i].size()) max_len = words[i].size();
            for (auto c : words[i])
                bitmap[i] |= 1<<(c-'a');
        }
        int res = 0;
        for (int i = 0; i < words.size(); i++) {
            if (max_len * words[i].size() <= res) continue;
            for (int t, j = i+1; j < words.size(); j++)
                if ((bitmap[i] & bitmap[j]) == 0 && (t = words[i].size() * words[j].size()) > res)
                    res = t;
        }
        return res;
    }
};
