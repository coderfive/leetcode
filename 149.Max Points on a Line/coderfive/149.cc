
class Solution {
    struct hash_pair {
        int operator() (const pair<int, int>& p) const {
            return std::hash<unsigned long long>()(
                    (((unsigned long long)(p.first)) << 32)
                    | ((unsigned long long)(p.second))
                );
        }
    };
public:
    int maxPoints(vector<Point>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); i++) {
            int overlap = 1, local_res = 0;
            unordered_map<pair<int,int>, int, hash_pair> mp;
            for (int j = 0; j < i; j++) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    overlap++;
                    continue;
                }
                int dy = points[j].y - points[i].y;
                int dx = points[j].x - points[i].x;
                if (dy < 0) {
                    dy = -dy;
                    dx = -dx;
                }
                int div = gcd(dy, dx);
                dy /= div;
                dx /= div;
                mp[make_pair(dy,dx)]++;
            }
            for (auto& p : mp)
                if (p.second > local_res)
                    local_res = p.second;
            local_res += overlap;
            if (local_res > res) res = local_res;
        }
        return res;
    }
    int gcd (int pos, int npos) {
        if (npos < 0) npos = -npos;
        while (pos && npos) {
            pos %= npos;
            std::swap (pos, npos);
        }
        return pos+npos;
    }
};
