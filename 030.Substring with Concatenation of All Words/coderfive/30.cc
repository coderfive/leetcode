class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.size() == 0 || words.size() == 0) return res;
        unordered_map<string, int> string_count;
        for (auto& str : words)
            string_count[str]++;
        int word_size = words[0].size();
        for (int i = 0; i < word_size; i++) {
            unordered_map<string, int> tmp_count;
            int total_count = 0;
            for (int j = i; j < s.size(); j += word_size) {
                string ts = s.substr(j, word_size);
                auto it = string_count.find(ts);
                if (it == string_count.end()) {
                    total_count = 0;
                    tmp_count.clear();
                    continue;
                }
                int sc = it->second;;
                int tc = tmp_count[ts];
                if (tc >= sc) {
                    int start = j-(word_size*total_count);
                    while (!std::equal(ts.begin(), ts.end(), s.begin()+start)) {
                        tmp_count[s.substr(start, word_size)]--;
                        total_count--;
                        start += word_size;
                    }
                    continue;
                }
                tmp_count[ts]++;
                total_count++;
                if (total_count == words.size()) {
                    total_count--;
                    int start = j-(words.size()-1)*word_size;
                    res.push_back(start);
                    tmp_count[s.substr(start, word_size)]--;
                }
            }
        }

        return res;
    }
};
