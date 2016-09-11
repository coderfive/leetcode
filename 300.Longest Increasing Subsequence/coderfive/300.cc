#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        map<int, int> mp;
        if (nums.empty()) return 0;
        mp[nums[0]] = 1;
        for (int i = 1; i < nums.size(); i++) {
            int n = nums[i];
            auto it = mp.lower_bound(n);
            if (it == mp.begin()) {
                if (it->first != n) mp[n] = 1;
            }
            else {
                it--;
                mp[n] = it->second+1;
            }
            it = mp.find(n);
            int freq = it->second;
            it++;
            while (it != mp.end() && it->second <= freq) {
                it = mp.erase(it);
            }
        }

        int res = 1;
        for (auto it : mp) {
            if (it.second > res) res = it.second;
        }
        return res;
    }
};

int main() {
    vector<int> v {3,1,2};
    Solution().lengthOfLIS(v);
    return 0;
}
