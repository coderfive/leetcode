#include <iostream>
#include <vector>
using namespace std;


class NumArray {
    vector<int> v;
    vector<int>& numbers;
    int get_sum (int i) {
        int res = 0;
        while (i > 0) {
            res += v[i];
            i -= i & -i;
        }
        return res;
    }
public:
    NumArray(vector<int> &nums) : numbers(nums) {
        v.resize(nums.size()+1);
        std::fill(v.begin(), v.end(), 0);
        for (int i = 0; i < nums.size(); i++)
            update_delta(i, nums[i]);
    }

    void update_delta (int i, int delta) {
        i++;
        while (i < v.size()) {
            v[i] += delta;
            i += i & -i;
        }
    }
    void update(int i, int val) {
        int t = val - numbers[i];
        numbers[i] = val;
        update_delta(i, t);
    }

    int sumRange(int i, int j) {
        return get_sum(j+1) - get_sum(i);
    }
};

int main() {
    vector<int> nums {1, 3, 5};
    NumArray n(nums);
    std::cout << n.sumRange(0,2) << std::endl;
    n.update(1,2);
    std::cout << n.sumRange(0,2) << std::endl;

    return 0;
}
