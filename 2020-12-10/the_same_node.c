//编写一个程序，找到两个单链表相交的起始节点。
//暴力解法struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
//	while (headA)//用headA的节点遍历headB
//	{
//		struct ListNode *newheadB = headB;
//		//用headA的节点遍历全部的headB节点
//		while (newheadB)
//		{
//			if ((newheadB == headA) && (headB->val != 0))//如果节点地址相等且值不为0就返回；
//				return newheadB;
//			newheadB = newheadB->next;
//		}
//		headA = headA->next;//headA节点后移
//	}
//	return NULL;//没有交点；  
//}

//双指针法：struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
//	struct ListNode *newheadA = headA;
//	struct ListNode *newheadB = headB;
//	while (newheadA != newheadB)//先判断再执行，都为空或者相等退出循环
//	{
//		不为空就走下去
//		为空换到第二个链表起点，这样两个指针对应的两个链表位置的长度就相等了
//		if (newheadA)
//			newheadA = newheadA->next;
//		else
//			newheadA = headB;
//		if (newheadB)
//			newheadB = newheadB->next;
//		else
//			newheadB = headA;
//		只会交换一次，因为交换过后两个指针剩余移动的链表的长度相等，
//		就没有结点，也会因为都是NULL而退出
//	}
//	return newheadB;