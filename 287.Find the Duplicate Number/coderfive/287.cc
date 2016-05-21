// n = nums.size()
// time complexity: O(n*lg(n))
// space: O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int minv = 1, maxv = nums.size(), mid;
        int nle;
        while (minv < maxv) {
            nle = 0;
            mid = (minv+maxv) / 2;
            for (auto n : nums)
                if (n <= mid) nle++;
            if (nle <= mid) {
                minv = mid+1;
            }
            else {
                maxv = mid;
            }
        }
        return minv;
    }
};
