/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

 /**
  *
  * @param pHead ListNode��
  * @return ListNode��
  */
struct ListNode* ReverseList(struct ListNode* pHead) {
    // write code here
    if (pHead == NULL) {
        return NULL;
    }
    struct ListNode* p = pHead;
    struct ListNode* q = NULL;
    struct ListNode* r = NULL;
    while (p) {
        q = p->next;
        p->next = r;
        r = p;
        p = q;

    }
    return r;
}