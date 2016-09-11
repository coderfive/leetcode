class Solution {
public:
    int hIndex(vector<int>& citations) {
        int sz = citations.size(), beg = 1, end, mid;
        end = sz;
        while (beg <= end) {
            mid = (beg+end) / 2;
            if (mid > citations[sz-mid]) {
                end = mid-1;
            }
            else if (mid == citations[sz-mid]) {
                return mid;
            }
            else {
                if ((sz-mid-1 < 0) || (sz-mid-1 >= 0 && mid >= citations[sz-mid-1]))
                    return mid;
                beg = mid+1;
            }
        }

        return 0;
    }
};
