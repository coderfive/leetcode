class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo = 0, mid, hi = nums.size()-1;
        if (nums.empty()) return false;
        while (lo < hi) {
            mid = lo + (hi-lo)/2;
            if (nums[mid] > target) {
                if (nums[mid] > nums[hi]) {
                    if (binary_search(nums.begin()+lo, nums.begin()+mid, target)) return true;
                    lo = mid+1;
                }
                else if (nums[mid] < nums[hi]) {
                    hi = mid;
                }
                else {
                    if (all_of(nums.begin()+mid, nums.begin()+hi, [&](const int& n) { return n == nums[mid];})) {
                        hi = mid;
                    }
                    else {
                        if (binary_search(nums.begin()+lo, nums.begin()+mid, target)) return true;
                        lo = mid+1;
                    }
                }
            }
            else if (nums[mid] < target) {
                if (nums[mid] > nums[hi]) {
                    lo = mid+1;
                }
                else if (nums[mid] < nums[hi]) {
                    if (binary_search(nums.begin()+mid, nums.begin()+hi+1, target)) return true;
                    hi = mid;
                }
                else {
                    if (all_of(nums.begin()+mid, nums.begin()+hi, [&](const int& n) { return n == nums[mid];})) {
                        hi = mid;
                    }
                    else {
                        lo = mid+1;
                    }
                }
            }
            else return true;
        }
        return nums[lo] == target;
    }
};
