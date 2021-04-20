 两数相加

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int next=0;
        ListNode * head=new ListNode(0);//头结点
         ListNode *cur=head;
        while(l1!=NULL||l2!=NULL||next!=0)
        {
            int num1=0;
            int num2=0;
            //得到两个链表之中的值
            if(l1!=NULL)
            num1=l1->val;
            if(l2!=NULL)
            num2=l2->val;

            int sum=(num1+num2+next)%10;//得到构建的值

           next=(num1+num2+next)/10;//得到进位

            //链接节点
            cur->next=new ListNode(sum);
            cur=cur->next;

            //往后挪动链表
            if(l1)
            l1=l1->next;
            if(l2)
            l2=l2->next;
        }

        if(head==cur)//没有加入新的值
        return head;

        else
        head=head->next;
        cur=NULL;
        return head;
        

    }
};

