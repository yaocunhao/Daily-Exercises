/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    138. 复制带随机指针的链表

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
        return head;

        Node *ret=new Node(head->val);
        Node *cur=ret;
        cur->next=NULL;

        Node *newnode=head;
        newnode=newnode->next;

        while(newnode)//全部拷贝过来
        {
            Node *next=new Node(newnode->val);
            next->next=NULL;
            cur->next=next;
            cur=cur->next;
            newnode=newnode->next;
        }
        //填入随机指针

        cur=ret;
        newnode=head;
        while(cur)
        {
            Node *copy_cur=ret;
            Node *copy_newnode=head;
            
            if(newnode->random==NULL)
            {
                cur->random=NULL;
            }
            else
            {
                while(newnode->random!=copy_newnode)
                {
                    copy_newnode=copy_newnode->next;
                    copy_cur=copy_cur->next;
                }
                cur->random=copy_cur;
            }
            cur=cur->next;
            newnode=newnode->next;
        }

        return ret;  
    }
};