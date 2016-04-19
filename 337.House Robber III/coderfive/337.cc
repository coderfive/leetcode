class Solution {
    pair<int, int> rob_helper (TreeNode* root) {
        pair<int, int> res (0, 0);
        if (!root) return res;
        auto left = rob_helper (root->left);
        auto right = rob_helper (root->right);
        res.first = root->val + left.second + right.second;
        res.second = std::max(left.first, left.second) + std::max(right.first, right.second);
        return res;
    }
public:
    int rob(TreeNode* root) {
        auto res = rob_helper(root);
        return std::max (res.first, res.second);
    }
};
