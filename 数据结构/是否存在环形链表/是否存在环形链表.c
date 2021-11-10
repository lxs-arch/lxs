/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return false;
    struct ListNode* p = head;
    struct ListNode* q = p->next;
    while (p != q) {
        if (q == NULL || q->next == NULL) {
            return false;
        }
        p = p->next;
        q = q->next->next;
    }
    return true;
}