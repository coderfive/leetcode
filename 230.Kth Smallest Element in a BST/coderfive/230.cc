class Solution {
    int get_kth (TreeNode* root, int& k) {
        if (!root) return 0;
        int res = get_kth(root->left, k);
        k--;
        if (k == 0)
            return root->val;
        if (k < 0) return res;
        return get_kth(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        return get_kth(root, k);
    }
};
