//��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 ���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL)
		return pHead;
	ListNode *newhead = (ListNode*)malloc(sizeof(ListNode));
	newhead->next = pHead;
	ListNode *prev = newhead;
	ListNode *cur = newhead->next;
	ListNode *next = cur->next;
	while (next)
	{
		if ((cur->val) == (next->val))
		{
			if ((next->next != NULL) && (next->next->next == NULL) && (next->val == next->next->val))
			{
				free(next->next);
				free(next);
				free(cur);
				prev->next = NULL;
				break;
			}
			prev->next = next->next;//�������Ľڵ�
			free(cur);//�ͷŵ�
			free(next);
			cur = prev->next;//cur�����ͷŵ������ڵ�֮��Ľڵ�
			if (cur)//��ֹԽ��
				next = cur->next;
			else
				break;
		}
		else
		{
			//����������
			prev = cur;
			cur = next;
			next = next->next;
		}
	}
	return newhead->next;
}
};