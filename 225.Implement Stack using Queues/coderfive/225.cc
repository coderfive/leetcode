class Stack {
    queue<int> que;
public:
    // Push element x onto stack.
    void push(int x) {
	que.push (x);
    }

    // Removes the element on top of the stack.
    void pop() {
	int sz = que.size();
	int t;
	for (int i = 1; i < sz; i++) {
	    t = que.front();
	    que.pop();
	    que.push(t);
	}
	que.pop();
    }

    // Get the top element.
    int top() {
	int sz = que.size();
	int t;
	for (int i = 0; i < sz; i++) {
	    t = que.front();
	    que.pop();
	    que.push(t);
	}
	return t;
    }

    // Return whether the stack is empty.
    bool empty() {
	return que.empty();
    }
};
