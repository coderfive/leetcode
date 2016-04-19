class Solution {
    bool verify_tree (const vector<bool>& is_null, int& idx) {
        if (idx >= is_null.size()) return false;
        if (is_null[idx++]) {
            return true;
        }
        if (!verify_tree (is_null, idx)) return false;
        return verify_tree(is_null, idx);
    }
public:
    bool isValidSerialization(string preorder) {
        vector<bool> is_null;
        int comma_count = std::count(preorder.begin(), preorder.end(), ',');
        is_null.resize(comma_count+1);
        int i = 0, n = 1;
        if (preorder[i] == '#') is_null[0] = true;
        else is_null[0] = false;
        while (n < is_null.size()) {
            while (preorder[i] != ',') i++;
            i++;
            if (preorder[i] == '#') is_null[n] = true;
            else is_null[n] = false;
            n++;
        }
        int idx = 0;
        if (!verify_tree (is_null, idx) || idx < is_null.size()) return false;
        return true;
    }
};
