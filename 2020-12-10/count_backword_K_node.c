//�����������K���ڵ��ֵ

struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
	struct ListNode*slow = pListHead;
	struct ListNode*fast = pListHead;
	while (k--)
	{
		if (fast)//��ֹK���ڽڵ����������Խ��
			fast = fast->next;//�ƶ�K��
		else
			return NULL;
	}
	while (fast)//fastΪ���ҵ��ڵ�
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}