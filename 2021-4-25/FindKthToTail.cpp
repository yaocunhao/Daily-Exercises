class Solution {
public:

    ListNode* FindKthToTail(ListNode* pHead, int k) {
       ListNode *slow=pHead;
        ListNode *quick=pHead;
      
      while(quick&&k)
      {
        quick=quick->next;
        k--;
      }
      if(k!=0)
        return NULL;
      
      while(quick)
      {
        slow=slow->next;
        quick=quick->next;
      }
      return slow;
      
    }
};