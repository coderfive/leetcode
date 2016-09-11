class Solution {
public:
    bool isPowerOfFour(int num) {
        int n = 1 + (4<<0) + (4<<2) + (4<<4);
        n = n + (n<<8) + (n<<16) + (n<<24);
        return num > 0 && ((num & (num-1)) == 0) && ((num & n) == num);
    }
};
