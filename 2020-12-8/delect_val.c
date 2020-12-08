#include<stdio.h>
#include <windows.h>
//删除链表中等于给定值 val 的所有节点。

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
	 while (cur->val == val)//将头个节点为val的全部删除
	 {
		 head = cur->next;//更头结点位置
		 free(cur);
		 cur = head;
		 if (head == NULL)
			 return head;
	 }
	 while (cur != NULL)
	 {
		 if (cur->val == val)
		 {
			 next = cur->next;//保存下一个节点的地址
			 free(cur);
			 prev->next = next;
			 cur = next;
		 }
		 else
		 {
			 prev = cur;//保存前面的位置            
			 cur = cur->next;
		 }
	 }
	 return head;

 }

//方法2：struct ListNode* removeElements(struct ListNode* head, int val){
//	struct ListNode *newnode = (struct ListNode *)malloc(sizeof(struct ListNode));//开辟个新节点
//	newnode->next = head;
//	struct ListNode *cur = newnode;
//	struct ListNode *prev = newnode;
//	struct ListNode *next = NULL;
//	while (cur != NULL)
//	{
//		
//		if (cur->val == val)
//		{
//			next = cur->next;//保存下一个节点位置
//			free(cur);
//			prev->next = next;
//			cur = next;
//		}
//		else
//		{
//			prev = cur;//保存前一个节点位置
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