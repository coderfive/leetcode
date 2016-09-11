class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode rh(0), tag(0), *po, *pe, *last_odd;
        last_odd = head;
        po = head;
        pe = &tag;
        while (po && po->next) {
            pe->next = po->next;
            pe = pe->next;
            po->next = pe->next;
            last_odd = po;
            po = po->next;
        }
        if (po) {
            po->next = tag.next;
        }
        else if (last_odd) {
            last_odd->next = tag.next;
        }
        if (pe && pe->next)
            pe->next = NULL;
        return head;
    }
};
