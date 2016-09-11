class NestedIterator {
    int next_value;
    bool next_valid;
    vector<int> idx;
    vector<const vector<NestedInteger>*> vi;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        next_valid = false;
        vi.push_back(&nestedList);
    }

    // called with next_valid == false
    void advance() {
        if (vi.size() == 0) return;
        if (vi.size() != idx.size()) {
            idx.push_back(0);
        }
        while (true) {
            auto &p = *vi.back();
            int& i = idx.back();
            if (p.size() <= i) {
                vi.pop_back();
                idx.pop_back();
                if (vi.size() == 0) break;
                idx.back()++;
                continue;
            }
            if (p[i].isInteger()) {
                next_valid = true;
                next_value = p[i].getInteger();
                idx.back()++;
                return;
            }
            else {
                vi.push_back(& p[i].getList());
                idx.push_back(0);
            }
        }
    }

    int next() {
        hasNext();
        next_valid = false;
        return next_value;
    }

    bool hasNext() {
        if (next_valid) return true;
        advance();
        return next_valid;
    }
};
