//class Solution {
//public:
//	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//		if (l1 == NULL)
//			return l2;
//		if (l2 == NULL)
//			return l1;
//		ListNode *newhead = NULL;
//		ListNode *tail = NULL;
//		//�ȸ�һ���ڵ���ͷ
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
//		//����������µ�ͷ֮���ٽ���β��
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
//		//һ��Ϊ��һ����Ϊ��
//		if (l1)
//			tail->next = l1;
//		else
//			tail->next = l2;
//		return newhead;
//
//	}
//};


//����2��
//public:
//	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//
//		ListNode *newhead = (ListNode*)malloc(sizeof(ListNode));//�ڱ�λ
//		ListNode *tail = newhead;
//		while (l1&&l2)
//		{
//			//ֱ�ӽ���β��
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
//		return (newhead->next);//�ڱ�λ�б������һ���ڵ�ĵ�ַ��
//
//	}
//};