//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
struct ListNode* p=l1,*q=l2;
struct ListNode* l3=(struct ListNode*)malloc(sizeof(struct ListNode));
struct ListNode* r3=l3;
while(p&&q){
    if((p->val)<=(q->val)){
        r3->next=p;
        r3=p;
        p=p->next;
    }
    else{
        r3->next=q;
        r3=q;
        q=q->next;
    }
}
if(!p){
    r3->next=q;
}
if(!q){
    r3->next=p;
}
return l3->next;
}