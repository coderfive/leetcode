/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    vector<TreeNode*> v;
public:
    BSTIterator(TreeNode *root) {
        while (root) {
            v.push_back(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !v.empty();
    }

    /** @return the next smallest number */
    int next() {
        int val = v.back()->val;
        TreeNode* last = v.back();
        if (last->right) {
            last = last->right;
            while (last) {
                v.push_back(last);
                last = last->left;
            }
        }
        else {
            v.pop_back();
            while (!v.empty() && v.back()->right == last) {
                last = v.back();
                v.pop_back();
            }
        }
        return val;
    }
};
