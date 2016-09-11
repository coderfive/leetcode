#include <vector>
#include <iostream>
using namespace std;

class Iterator {
    vector<int>::const_iterator beg, end;
public:
    Iterator(const vector<int>& nums) {
        beg = nums.begin();
        end = nums.end();
    }
    // Returns the next element in the iteration.
    int next() {
        return *beg++;
    }
    // Returns true if the iteration has more elements.
    bool hasNext() const {
        return beg != end;
    }
};

class PeekingIterator : public Iterator {
    bool next_valid;
    int next_value;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	   next_valid = false; 
	   next_value = 1; 
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
//            print_info("peek: ");
            if (!next_valid) {
                next_valid = true;
                next_value = Iterator::next(); 
            }
            return next_value;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
 //           print_info("next: ");
            if (next_valid) {
                next_valid = false;
                return next_value;
            }
            return Iterator::next();
	}

        void print_info (const std::string& prefix) const {
            std::cout << prefix << "next_valid = " << next_valid 
                      << ", next_value = " << next_value << std::endl;
        }
	bool hasNext() const {
  //          print_info("hasNext: ");
            if (next_valid) return true;
            return Iterator::hasNext();
	}
};


void do_test (int op, PeekingIterator& pi) {
    switch (op) {
        case 0: // hasNext
            std::cout << pi.hasNext() << std::endl;
            break;
        case 1: // peek
            std::cout << pi.peek() << std::endl;
            break;
        default: // next
            std::cout << pi.next() << std::endl;
            break;
    }
}

int main() {
    vector<int> v {1,2,3,4};
    std::cout.setf(std::iostream::boolalpha);
    PeekingIterator p (v);
    vector<int> ops {0,1,1,2,2,1,1,2,0,1,0,2,0};
    for (auto op : ops)
        do_test(op, p);

    return 0;
}




