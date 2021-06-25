class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //两个节点的值相加，并且进行尾插
        //注意进制的存在

        ListNode* head= new ListNode(0);//哨兵位
        ListNode* cur=head;
       
        int next=0; 
        while(l1||l2||next)
        {
            int num1=0;
            int num2=0;
            if(l1)
                num1=l1->val;
            if(l2)
                num2=l2->val;
            
            int num=num1+num2+next;

            next=num/10;
            num=num%10;

            cur->next=new ListNode(num);
            cur=cur->next;
            if(l1)
                l1=l1->next;
            if(l2)
                l2=l2->next;
        }
        return head->next;
    }
};