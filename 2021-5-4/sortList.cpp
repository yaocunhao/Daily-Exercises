 排序链表
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

 class Greater
 {
     public:
     int operator()(const ListNode *x,const ListNode *y)
     {
         return x->val>y->val;
     }
 };
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        priority_queue<ListNode*,vector<ListNode*>,Greater> q;

        ListNode *Head=head;
        while(Head)
        {
            q.push(Head);
            Head=Head->next;
        } 

        ListNode *newhead=new ListNode;
        ListNode *cur=newhead;
        while(!q.empty())
        {
            cur->next=q.top();
            q.pop();
            cur=cur->next;
        }
        cur->next=NULL;
        return newhead->next;

    }
};

