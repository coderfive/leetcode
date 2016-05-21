class Solution {
    void connect(TreeLinkNode *root, int level, vector<TreeLinkNode*>& v) {
        if (level == v.size()) v.push_back(root);
        else {
            v[level]->next = root;
            v[level] = root;
        }
        if (root->left)
            connect(root->left, level+1, v);
        if (root->right)
            connect(root->right, level+1, v);
    }
public:
    void connect(TreeLinkNode *root) {
	if (!root) return;
        vector<TreeLinkNode*> v;
        connect(root, 0, v);
        for (auto& p : v)
            p->next = NULL;
    }
};
