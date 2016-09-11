class Solution {
public:
    void connect(TreeLinkNode *root) {
	if (!root) return;
        root->next = NULL;
        TreeLinkNode *cur = root, *lower = NULL, *next_cur = NULL;
        while (cur) {
            if (cur->left) {
                if (lower) lower->next = cur->left;
                else next_cur = cur->left;
                lower = cur->left;
            }
            if (cur->right) {
                if (lower) lower->next = cur->right;
                else next_cur = cur->right;
                lower = cur->right;
            }
            cur = cur->next;
            if (!cur) {
                if (lower) lower->next = NULL;
                cur = next_cur;
                lower = next_cur = NULL;
            }
        }
    }
};
