/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        //给定一个哈希表，几率链表之中的节点是否出现过

        if(head==NULL||head->next==NULL)
            return head;

        ListNode* prev=head;
        ListNode* next=head->next;
        unordered_map<int,int> mp;

        mp[prev->val]++;

        while(next)
        {
            if(mp[next->val]==0)
            {
                mp[next->val]++;
                prev->next=next;
                prev=next;
            }
            next=next->next;
        }
        prev->next=next;
        return head;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        //不用哈希表，时间换空间
        if(head==NULL||head->next==NULL)
            return head;

        ListNode* prev=head;
        ListNode* next=head->next;

        while(next)
        {
            int flag=0;

            if(prev->val==next->val)
                flag=1;

            //查询是否出现过了
            ListNode *newhead=head;
            while(newhead!=prev&&flag==0)
            {
                if(newhead->val==next->val)
                {
                    flag=1;
                    break;
                }
                newhead=newhead->next;
            }

            if(flag==0)//没有出现过
            {
                prev->next=next;
                prev=next;
            }
            next=next->next;
        }
        prev->next=next;
        return head;
    }
};

