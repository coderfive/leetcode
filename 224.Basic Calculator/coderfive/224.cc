class Solution {
    void consume_space (const string& s, int& idx) {
	while (idx < s.size() && std::isspace(s[idx])) idx++;
    }
    int next_int (const string& s, int& idx) {
	int res = 0;
	while (std::isdigit(s[idx])) {
	    res = res*10 + (s[idx++]-'0');
	}
	return res;
    }
    public:
    int calculate(string s) {
	int idx = 0, t;
	vector<int> res;
	vector<char> op;
	while (true) {
	    consume_space (s, idx);
	    if (idx >= s.size()) return res[0];
	    if (s[idx] == '(' || s[idx] == '+' || s[idx] == '-') {
		op.push_back(s[idx]);
		idx++;
	    }
	    else {
		if (s[idx] == ')') {
		    idx++;
		    op.pop_back();
		}
		else {
		    res.push_back(next_int (s, idx));
		}
		if (!op.empty() && op.back() != '(') {
		    t = res.back();
		    res.pop_back();
		    if (op.back() == '+')
			res.back() += t;
		    else
			res.back() -= t;
		    op.pop_back();
		}
	    }
	}
	return res[0];
    }
};

