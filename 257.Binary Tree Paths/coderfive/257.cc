class Solution {
    void travese (TreeNode* root, string& prefix, vector<string>& res) {
        int sz = prefix.size();
        if (!root) {
            return;
        }
        prefix += std::string("->");
        prefix += std::to_string(root->val);
        if (!root->left && !root->right) {
            res.push_back(prefix);
        }
        travese(root->left, prefix, res);
        travese(root->right, prefix, res);
        prefix.resize(sz);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string prefix;
        if (root) {
            prefix = std::to_string(root->val);
            travese(root->left, prefix, res);
            travese(root->right, prefix, res);
            if (!root->left && !root->right) {
                res.push_back(prefix);
        }
        }
        return res;
    }
};
