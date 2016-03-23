class Solution {
public:
    int next_int (int st, int cnt, int sum) {
        if (cnt == 1) {
            if (sum <= 9 && sum >= st) return sum;
            return -1;
        }
        while (st+cnt-1 <= 9) {
            if (((st+st+cnt-1)*cnt)/2 > sum) return -1;
            if (((9+9-cnt+1)*cnt)/2 < sum) return -1;
            if (st + ((9+9-cnt+2)*(cnt-1))/2 >= sum) return st;
            st++;
        }
        return -1;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tmp (k);
        vector<vector<int>> res;
        int i = 1, sum = 0, t;
        if (k <= 0) return res;
        tmp[0] = next_int (1, k, n);
        sum = tmp[0];
        if (tmp[0] < 0) return res;
        while (true) {
            while (i < k) {
                tmp[i] = next_int (tmp[i-1]+1, k-i, n-sum);
                sum += tmp[i];
                i++;
            }
            res.push_back(tmp);
            i--;
            sum -= tmp[i];
            i--;
            while (i >= 0) {
                sum -= tmp[i];
                tmp[i] = next_int (tmp[i]+1, k-i, n-sum);
                if (tmp[i] > 0) {
                    sum += tmp[i];
                    i++;
                    break;
                }
                i--;
            }
            if (i < 0) break;
        }

        return res;
    }
};
