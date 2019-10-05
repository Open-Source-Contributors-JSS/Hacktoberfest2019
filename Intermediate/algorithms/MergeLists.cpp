/**
 * Given this definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class MergeLists {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if (!a || b && a->val > b->val) swap(a, b);
        if (a) a->next = mergeTwoLists(a->next, b);
        return a;
    }
};