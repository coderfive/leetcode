class Solution {
    ListNode* reverse_list (ListNode* head) {
        ListNode *last = NULL, *cur, *tmp;
        cur = head;
        while (cur) {
            tmp = cur->next;
            cur->next = last;
            last = cur;
            cur = tmp;
        }
        return last;
    }
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* firstHalf, *secondHalf, *saved_head = head;
        int num = 0;
        while (head) {
            num++;
            head = head->next;
        }
        bool res = true;
        int n = num/2;
        secondHalf = saved_head;
        while (n--) {
            secondHalf = secondHalf->next;
        }
        secondHalf = reverse_list(secondHalf);
        auto saved_secondHalf = secondHalf;
        firstHalf = saved_head;
        n = num/2;
        while (n--) {
            if (firstHalf->val != secondHalf->val) {
                res = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        reverse_list(saved_secondHalf);

        return res;
    }
};
