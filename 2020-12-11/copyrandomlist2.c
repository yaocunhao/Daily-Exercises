//�����Ͻڵ�����½ڵ���棬����γ��������ȵ�������
//���������λ�õĹ�ϵ����������������
struct Node* copyRandomList(struct Node* head) {
	if (head == NULL)
		return head;
	struct Node *cur = head;
	while (cur)
	{
		struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
		//���½ڵ㸴���Ͻڵ㣬���Ҳ����½ڵ���
		temp->val = cur->val;
		temp->next = cur->next;
		temp->random = cur->random;
		cur->next = temp;
		cur = temp->next;
	}
	//��ʱ�Ѿ��������Ŀ������µ�����Ϊ�¾��γɵĳ�����
	cur = head->next;//�õ��������ͷ
	struct Node *newhead = cur;//�����������ͷ��
	while (cur)
	{
		if (cur->random != NULL)
			cur->random = cur->random->next;//�µĽڵ���Զ�����������һ����
		if (cur->next != NULL)
			cur->next = cur->next->next;
		cur = cur->next;//�ƶ�����һ���µĽڵ�
	}
	return newhead;