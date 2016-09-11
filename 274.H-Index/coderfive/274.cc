class Solution {
public:
    int hIndex(vector<int>& citations) {
        std::sort(citations.begin(), citations.end());
        int sz = citations.size();
        int i = sz;
        for (; i > 0; i--) {
            if (citations[sz-i] >= i && (sz-i-1 < 0 || citations[sz-i-1] <= i)) return i;
        }

        return 0;
    }
};
