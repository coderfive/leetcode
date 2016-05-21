class Solution {
    TreeNode* anc;
    bool found_p, found_q;
    void populate (TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return;
        bool not_found = !found_p && !found_q;
        populate(root->left, p, q);
        populate(root->right, p, q);
        if (anc) return;
        if (root == p) {
            found_p = true;
        }
        if (root == q) {
            found_q = true;
        }
        if (not_found && found_p && found_q) anc = root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        anc = nullptr;
        found_p = found_q = false;
        populate(root, p, q);
        return anc;
    }
};
