class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int mp[128];
        mp['A'] = 0;
        mp['C'] = 1;
        mp['G'] = 2;
        mp['T'] = 3;
        mp[0] = 'A';
        mp[1] = 'C';
        mp[2] = 'G';
        mp[3] = 'T';
        int mask = (1<<20)-1;
        unordered_map<int, int> unmap;
        vector<string> vs;
        int key = 0;
        if (s.size() < 10) return vs;
        for (int i = 0; i < 9; i++)
            key = (key<<2) + mp[s[i]];
        for (int i = 9; i < s.size(); i++) {
            key = (key<<2) + mp[s[i]];
            key &= mask;
            unmap[key]++;
        }
        string tmp;
        tmp.resize(10);
        for (auto& p : unmap) {
            if (p.second > 1) {
                int key = p.first;
                for (int i = 0; i < 10; i++, key>>=2) {
                    tmp[9-i] = mp[key&3];
                }
                vs.push_back(tmp);
            }
        }

        return vs;
    }
};
