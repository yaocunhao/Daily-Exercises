剑指 Offer 24. 反转链表

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL)
        return head;

        ListNode *newhead=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return newhead;


    }


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL)
        return head;

        ListNode *prev=head;
        ListNode *cur=head->next;
        ListNode *next=cur->next;
        prev->next=NULL;

        while(cur!=NULL)
        {
            cur->next=prev;
            prev=cur;
            cur=next;
            if(next!=NULL)
            next=next->next;
        }
        return prev;

    }
};