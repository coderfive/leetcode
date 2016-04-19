class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
	if (!root) return root;
	std::swap (root->left, root->right);
	invertTree(root->left);
	invertTree(root->right);
	return root;
    }
};
