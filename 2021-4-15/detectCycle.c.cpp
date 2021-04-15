142. 环形链表 II

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
    ListNode *detectCycle(ListNode *head) {
        //一快一慢指针，一起出发最后肯定会相遇
        //慢指针走1步，快指针走两步，那么他们之间的距离为x
        //那么，每次挪动一次减少的距离为x-1
        //如果快指针为其它步数，比如每次挪动减少距离为x-2，x-3，当在极端条件下，就无法相遇
        //两个指针都从入环点出发，那么会在入环点相遇，因此慢指针最多走完一圈就要和快指针相遇
        //x=n圈-y

        ListNode *slow=head;
        ListNode *fast=head;

        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            break;
        }
        if(fast==NULL||fast->next==NULL)
            return NULL;
        
        //有环

        fast=head;
        while(slow!=fast)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return fast;
        
    }
};