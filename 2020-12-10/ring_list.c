////����һ�������ж��������Ƿ��л���
//
//�����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ��� Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� ��� pos �� - 1�����ڸ�������û�л���ע�⣺pos ����Ϊ�������д��ݣ�������Ϊ�˱�ʶ�����ʵ�������
//
//��������д��ڻ����򷵻� true �� ���򣬷��� false ��
//
//
//bool hasCycle(struct ListNode *head) {
//	if (head == NULL || head->next == NULL)
//		return false;//���������ɻ�
//	struct ListNode *prev = head;
//	struct ListNode *cur = head->next;
//	while (cur)
//	{
//		if (cur == prev)//�غϴ����л�
//		{
//			return true;
//		}
//		//�������ƶ�
//		prev = prev->next;
//		if (cur->next == NULL)//С��Խ��
//			return false;
//		cur = cur->next->next;
//	}
//	return false;
//}