class Solution {
    int left_nodes (TreeNode* node) {
	int res = 0;
	while (node) {
	    res++;
	    node = node->left;
	}
	return res;
    }
    int right_nodes (TreeNode* node) {
	int res = 0;
	while (node) {
	    res++;
	    node = node->right;
	}
	return res;
    }
public:
    int countNodes(TreeNode* root) {
	int res = 0, left, right, mid;
	while (root) {
	    left = left_nodes (root->left);
	    right = right_nodes (root->right);
	    if (left == right) {
		res += (1<<(left+1)) - 1;
		root = nullptr;
	    }
	    else {
		mid = right_nodes (root->left);
		if (mid == left) {
		    res += 1<<left;
		    root = root->right;
		}
		else {
		    res += 1<<right;
		    root = root->left;
		}
	    }
	}

	return res;
    }
};
