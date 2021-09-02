class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        //双指针，一个指针先走K步，然后两个指针同时走，
        //当先走的指针为空的时候，前面的指针指向的就是倒数第K个节点

        ListNode* next=head;
        int n=k;
        while(n--)
        {
            next=next->next;
        }
        ListNode* cur=head;
        while(next)
        {
            cur=cur->next;
            next=next->next;
        }

        return cur;
    }
};