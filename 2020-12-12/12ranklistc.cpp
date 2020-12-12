#include <windows.h>
////对链表进行插入排序
//struct ListNode* insertionSortList(struct ListNode* head){
//	if (head == NULL)
//		return head;
//	struct ListNode *newhead = (struct ListNode*)malloc(sizeof(struct ListNode));//哨兵位
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
//				next_prev->next = next->next;//保存后面的节点
//				prev->next = next;//插到前面
//				next->next = cur;
//				cur = prev->next;//cur回到起点位置
//				next = next_prev->next;//next指针位置更新
//			}
//			else//往后挪
//			{
//				next_prev = next;
//				next = next->next;
//
//			}
//		}
//		//完成一个点的比较，cur此时已经是最小的，往后挪进行下一个点的比较
//		prev = cur;
//		cur = cur->next;
//	}
//	return newhead->next;
//}




