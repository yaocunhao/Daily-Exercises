//��дһ�������ҵ������������ཻ����ʼ�ڵ㡣
//�����ⷨstruct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
//	while (headA)//��headA�Ľڵ����headB
//	{
//		struct ListNode *newheadB = headB;
//		//��headA�Ľڵ����ȫ����headB�ڵ�
//		while (newheadB)
//		{
//			if ((newheadB == headA) && (headB->val != 0))//����ڵ��ַ�����ֵ��Ϊ0�ͷ��أ�
//				return newheadB;
//			newheadB = newheadB->next;
//		}
//		headA = headA->next;//headA�ڵ����
//	}
//	return NULL;//û�н��㣻  
//}

//˫ָ�뷨��struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
//	struct ListNode *newheadA = headA;
//	struct ListNode *newheadB = headB;
//	while (newheadA != newheadB)//���ж���ִ�У���Ϊ�ջ�������˳�ѭ��
//	{
//		��Ϊ�վ�����ȥ
//		Ϊ�ջ����ڶ���������㣬��������ָ���Ӧ����������λ�õĳ��Ⱦ������
//		if (newheadA)
//			newheadA = newheadA->next;
//		else
//			newheadA = headB;
//		if (newheadB)
//			newheadB = newheadB->next;
//		else
//			newheadB = headA;
//		ֻ�ύ��һ�Σ���Ϊ������������ָ��ʣ���ƶ�������ĳ�����ȣ�
//		��û�н�㣬Ҳ����Ϊ����NULL���˳�
//	}
//	return newheadB;