class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        vector<TreeNode*> v;
        if (!root) return res;
        v.push_back(root);

        while (!v.empty()) {
            TreeNode* node = v.back();
            if (node->left)
                v.push_back(node->left);
            else if (node->right)
                v.push_back(node->right);
            else {
                res.push_back (v.back()->val);
                v.pop_back();
                while (!v.empty()) {
                    if (v.back()->right == node || !v.back()->right) {
                        node = v.back();
                        v.pop_back();
                        res.push_back(node->val);
                    }
                    else {
                        v.push_back(v.back()->right);
                        break;
                    }
                }
            }
        }

        return res;
    }
};
