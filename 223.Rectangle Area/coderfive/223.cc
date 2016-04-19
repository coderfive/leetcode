#include <iostream>

class Solution {
    struct point {
	int x, y;
    };
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	point alb, aur, blb, bur;
	alb.x = A;
	alb.y = B;
	aur.x = C;
	aur.y = D;
	blb.x = E;
	blb.y = F;
	bur.x = G;
	bur.y = H;
	int a = (aur.y-alb.y) * (aur.x-alb.x);
	int b = (bur.y-blb.y) * (bur.x-blb.x);
	int h, w;
       	if (std::min(aur.y, bur.y) > std::max(alb.y, blb.y) &&
	    std::min(aur.x, bur.x) > std::max(alb.x, blb.x)) {
	    h = std::min(aur.y, bur.y) - std::max(alb.y, blb.y);
	    w = std::min(aur.x, bur.x) - std::max(alb.x, blb.x);
	    b -= w*h;
	}
	return a+b;
    }
};

int main() {
    std::cout << Solution() . computeArea(-1, 0, 0, 1, 1, -1, 2, 0) << std::endl;

    return 0;
}
