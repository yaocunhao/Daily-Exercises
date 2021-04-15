 对链表进行插入排序


class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
        return head;

    ListNode *newhead=new ListNode;
    newhead->next=head;//哨兵位

    ListNode *cur=head->next;
    newhead->next->next=NULL;
    ListNode *tail=newhead->next;
    while(cur)
    {
        ListNode *next=cur->next;
        ListNode *front=newhead->next;

        if(cur->val<=front->val)//头插
        {
            cur->next=front;
            newhead->next=cur;
        }
        else if(cur->val>=tail->val)//尾插
        {
            tail->next=cur;
            cur->next=NULL;
            tail=cur;
        }
        else//中间插
        {
            while(front)
            {
                if(cur->val>=front->val&&cur->val<=front->next->val)
                {
                    cur->next=front->next;
                    front->next=cur;
                    break;
                }
                else
                front=front->next;
            }
        }
        cur=next;
    }   

    return newhead->next;
    }
   
};