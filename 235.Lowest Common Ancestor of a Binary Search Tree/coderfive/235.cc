class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!p || !q) {
            if (p) return p;
            return q;
        }
        if (!root) return root;
        if (p->val > q->val) std::swap (p, q);
        while (true) {
            if (root->val < p->val) {
                root = root->right;
            }
            else if (root->val > q->val) {
                root = root->left;
            }
            else
                return root;
        }

        return root;
    }
}; 
