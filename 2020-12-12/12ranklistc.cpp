#include <windows.h>
////��������в�������
//struct ListNode* insertionSortList(struct ListNode* head){
//	if (head == NULL)
//		return head;
//	struct ListNode *newhead = (struct ListNode*)malloc(sizeof(struct ListNode));//�ڱ�λ
//	newhead->next = head;
//	struct ListNode *cur = newhead->next;
//	struct ListNode *prev = newhead;
//	while (cur->next)
//	{
//		struct ListNode *next_prev = cur;
//		struct ListNode *next = cur->next;
//		while (next)
//		{
//			if ((next->val) <= (cur->val))
//			{
//				next_prev->next = next->next;//�������Ľڵ�
//				prev->next = next;//�嵽ǰ��
//				next->next = cur;
//				cur = prev->next;//cur�ص����λ��
//				next = next_prev->next;//nextָ��λ�ø���
//			}
//			else//����Ų
//			{
//				next_prev = next;
//				next = next->next;
//
//			}
//		}
//		//���һ����ıȽϣ�cur��ʱ�Ѿ�����С�ģ�����Ų������һ����ıȽ�
//		prev = cur;
//		cur = cur->next;
//	}
//	return newhead->next;
//}




