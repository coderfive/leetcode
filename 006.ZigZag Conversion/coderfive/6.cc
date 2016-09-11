class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string res = s;
        int k = 0;
        for (int i = 0; i < numRows; i++) {
            int period[2] = {2*(numRows-i-1), i*2};
            if (i == 0 || i == numRows-1) period[0] = period[1] = (numRows-1)*2;
            for (int j = i, t = 0; j < s.size(); j += period[t++&1])
                res[k++] = s[j];
        }
        return res;
    }
};
