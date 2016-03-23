#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
	k = nums.size()-k;
	int st = 0, end = nums.size()-1;
	int s, e, m, pivot;
	while (end-st > 2) {
	    m = (st+end)/2;
	    s = st;
	    e = end;
	    if (nums[s] < nums[m]) {
		if (nums[e] < nums[s]) pivot = nums[s];
		else if (nums[e] < nums[m]) pivot = nums[e];
		else pivot = nums[m];
	    }
	    else {
		if (nums[e] < nums[m]) pivot = nums[m];
		else if (nums[e] < nums[s]) pivot = nums[e];
		else pivot = nums[s];
	    }
	    while (true) {
		while (s < e && nums[s] <= pivot) s++;
		while (e > s && nums[e] > pivot) e--;
		if (s < e)
		    std::swap(nums[s++], nums[e--]);
		else 
		    break;
	    }
	    if (nums[s] > pivot) s--;
	    if (s-st > k) {
		if (end == s) s--;
		end = s;
	    }
	    else if (s-st == k) {
		return *std::max_element(nums.begin()+st, nums.begin()+s+1);
	    }
	    else {
		k -= s-st+1;
		st = s+1;
	    }
	}
	std::sort (nums.begin()+st, nums.begin()+end+1);
	return nums[st+k];
    }
};

int main() {
    vector<int> v1 {3,1,2,4};
    std::cout << Solution().findKthLargest(v1, 2) << std::endl;

    vector<int> v2 {2,1};
    std::cout << Solution().findKthLargest(v2, 1) << std::endl;

    return 0;
}
