删除链表的倒数第 N 个结点

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode *prev=head;
        ListNode *cur=head;
        ListNode *next=head;

       int _n=n;
        while(_n--)
        {
            next=next->next;
        }
        while(next)
        {
            prev=cur;
            cur=cur->next;
            next=next->next;            
        }

        prev->next=cur->next;
        if(prev==cur&&n==1)//只有一个节点，且要删除
        return nullptr;
        
        if(prev==cur)//不止一个节点，且要删除
        head=prev->next;

        
        return head;

    }
};