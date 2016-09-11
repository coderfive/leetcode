class Solution {
    int next_int (const string& s, int& idx) {
	consume_space(s, idx);
	int res = 0;
	while (idx < s.size() && std::isdigit(s[idx])) {
	    res = res * 10 + (s[idx++] - '0');
	}
	consume_space(s, idx);
	return res;
    }
    void consume_space (const string& s, int& idx) {
	while (idx < s.size() && std::isspace(s[idx])) idx++;
    }
public:
    int calculate(string s) {
	int idx = 0, t;
	vector<int> res;
	vector<char> op;
	consume_space(s, idx);
	res.push_back(next_int(s, idx));
	while (true) {
	    consume_space(s, idx);
	    while (idx < s.size() && (s[idx] == '*' || s[idx] == '/')) {
		if (s[idx++] == '*')
		    res.back() *= next_int(s, idx);
		else
		    res.back() /= next_int(s, idx);
	    }
	    if (idx >= s.size()) break;
	    if (!op.empty()) {
		if (op[0] == '+')
		    res[0] += res[1];
		else
		    res[0] -= res[1];
		op[0] = s[idx++];
		res[1] = next_int(s, idx);
	    }
	    else {
		op.push_back(s[idx++]);
		res.push_back(next_int(s, idx));
	    }
	}
	if (!op.empty()) {
	    if (op[0] == '+')
		res[0] += res[1];
	    else
		res[0] -= res[1];
	}
	return res[0];
    }
};
