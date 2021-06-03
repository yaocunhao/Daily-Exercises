
    ListNode *reverse(ListNode *head)//链表逆转
    {
      if(head==nullptr||head->next==nullptr)
        return head;
      
      ListNode *newhead=reverse(head->next);
      head->next->next=head;
      head->next=nullptr;
      return newhead;
    }
  
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr||k==0||head->next==nullptr)
            return head;
      
      vector<ListNode*>arr;//保存每个反转后的头结点
      ListNode *prev=head;
      ListNode *cur=head;
      
      while(cur)
      {
        int count=1;
        while(cur&&count!=k)
        {
          cur=cur->next;
          count++;//来到翻转点
        }
        ListNode *next=nullptr;//保存下一个头结点
        if(cur!=nullptr)//进行翻转
        {
          next=cur->next;//保存下一个节点
          cur->next=nullptr;
          arr.push_back(reverse(prev));//将翻转后的头结点保存起来
          prev=cur=next;//进行更新
        }
        else//剩余节点不够了，不进行反转
        {
          arr.push_back(prev);
          break;
        }
      }
      
      //进行链表的链接
      ListNode* rethead=arr[0];//返回的链表的头
      cur = rethead;
      for(int i=1;i<arr.size();i++)
      {
        ListNode *temp=arr[i];
        while(cur->next)//走到当前链表的末尾
        {
          cur=cur->next;
        }
        cur->next=temp;//将链表链接起来
        cur=temp;//更新链表的头
      }
      
      return rethead;
    }
};