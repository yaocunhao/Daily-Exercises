#include<stdio.h>
#include <windows.h>
//ɾ�������е��ڸ���ֵ val �����нڵ㡣

// Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };

 struct ListNode* removeElements(struct ListNode* head, int val){
	 if (head == NULL)
	 {
		 return head;
	 }

	 struct ListNode *cur = head;
	 struct ListNode *prev = NULL;
	 struct ListNode *next = NULL;
	 while (cur->val == val)//��ͷ���ڵ�Ϊval��ȫ��ɾ��
	 {
		 head = cur->next;//��ͷ���λ��
		 free(cur);
		 cur = head;
		 if (head == NULL)
			 return head;
	 }
	 while (cur != NULL)
	 {
		 if (cur->val == val)
		 {
			 next = cur->next;//������һ���ڵ�ĵ�ַ
			 free(cur);
			 prev->next = next;
			 cur = next;
		 }
		 else
		 {
			 prev = cur;//����ǰ���λ��            
			 cur = cur->next;
		 }
	 }
	 return head;

 }

//����2��struct ListNode* removeElements(struct ListNode* head, int val){
//	struct ListNode *newnode = (struct ListNode *)malloc(sizeof(struct ListNode));//���ٸ��½ڵ�
//	newnode->next = head;
//	struct ListNode *cur = newnode;
//	struct ListNode *prev = newnode;
//	struct ListNode *next = NULL;
//	while (cur != NULL)
//	{
//		
//		if (cur->val == val)
//		{
//			next = cur->next;//������һ���ڵ�λ��
//			free(cur);
//			prev->next = next;
//			cur = next;
//		}
//		else
//		{
//			prev = cur;//����ǰһ���ڵ�λ��
//			cur = cur->next;
//		}
//	}
//	return (head = newnode->next);
//}


int main()
{
	struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->val = 100;
	head->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->next->val = 200;
	head->next ->next= (struct ListNode *)malloc(sizeof(struct ListNode));
	head->next->next->val = 300;
	head->next->next->next = NULL;
	head=removeElements(head, 100);
	while (head != NULL)
	{
		printf("%d\n", head->val);
		head = head->next;
	}
	system("pause");
	return 0;
}