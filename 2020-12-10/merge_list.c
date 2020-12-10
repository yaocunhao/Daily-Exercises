//class Solution {
//public:
//	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//		if (l1 == NULL)
//			return l2;
//		if (l2 == NULL)
//			return l1;
//		ListNode *newhead = NULL;
//		ListNode *tail = NULL;
//		//先给一个节点做头
//		if ((l1->val)<(l2->val))
//		{
//			newhead = tail = l1;
//			l1 = l1->next;
//		}
//		else
//		{
//			newhead = tail = l2;
//			l2 = l2->next;
//		}
//		//在上面给完新的头之后再进行尾插
//		while (l1&&l2)
//		{
//			if ((l1->val)<(l2->val))
//			{
//				tail->next = l1;
//				l1 = l1->next;
//			}
//			else
//			{
//				tail->next = l2;
//				l2 = l2->next;
//			}
//			tail = tail->next;
//		}
//		//一个为空一个不为空
//		if (l1)
//			tail->next = l1;
//		else
//			tail->next = l2;
//		return newhead;
//
//	}
//};


//方法2：
//public:
//	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//
//		ListNode *newhead = (ListNode*)malloc(sizeof(ListNode));//哨兵位
//		ListNode *tail = newhead;
//		while (l1&&l2)
//		{
//			//直接进行尾插
//			if ((l1->val)<(l2->val))
//			{
//				tail->next = l1;
//				l1 = l1->next;
//			}
//			else
//			{
//				tail->next = l2;
//				l2 = l2->next;
//			}
//			tail = tail->next;
//		}
//		if (l1)
//			tail->next = l1;
//		else
//			tail->next = l2;
//		return (newhead->next);//哨兵位中保存的下一个节点的地址；
//
//	}
//};