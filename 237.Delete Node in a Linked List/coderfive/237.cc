class Solution {
public:
    void deleteNode(ListNode* node) {
        auto next = node->next;
        std::swap (node->val, next->val);
        node->next = next->next;
    }
};
