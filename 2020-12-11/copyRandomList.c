//**˼·����**
//��Ȼ����ȿ�����ԭ�����ж��ٸ��ڵ����ǾͿ��ٶ��ٸ��ڵ㣬��ԭ�ڵ����ݿ��������б�ڵ㣬Ȼ�����������Ҵ�������ֻʣ�����ָ��û�������ˣ���ʱ����ѭ�����õ��������и����ڵ�����ָ��ָ���λ�ã��������λ��ȥ�������н���Ѱ�ң��������������ȿ�����


/**
* Definition for a Node.
* struct Node {
*     int val;
*     struct Node *next;
*     struct Node *random;
* };
*/

struct Node* copyRandomList(struct Node* head) {
	if (head == NULL)
		return head;
	struct Node *newhead = (struct Node*)malloc(sizeof(struct Node));//�����½ڵ�
	struct Node *node = head;//head�ĵ�ַ���滹Ҫ�õ�
	newhead->val = head->val;//��������
	newhead->next = NULL;
	node = node->next;
	struct Node *tail = newhead;
	while (node)//����N���ڵ㽫�����N���ڵ�����ݿ�����ȥ
	{
		struct Node *temp = (struct Node*)malloc(sizeof(struct Node));//���ٽڵ�װԭ�����ֵ
		temp->val = node->val;//��������
		temp->next = NULL;
		tail->next = temp;//����β��
		tail = tail->next;
		node = node->next;
	}
	//���������������������ֻȱ��random_index���������random_index����д

	struct Node *cur_newhead = newhead;
	struct Node *cur = head;
	while (cur)
	{
		int count = 0;//������
		struct Node *next_newhead = newhead;
		struct Node *next = head;//���������������Ѱ�Ҷ�Ӧλ�õģ�ѭ��һ������һ��
		while (next)//nextΪ��˵��û���ҵ�
		{
			if (cur->random == next)//�ҵ����ָ��ĵ�ַ
				break;
			count++;
			next = next->next;//����
		}
		if (next == NULL)//���ָ��Ϊ��
		{
			cur_newhead->random = NULL;
			cur_newhead = cur_newhead->next;//����һ���ڵ����д
		}
		else
		{
			while (count--)//count�������Ӧ��λ�ã����������������������ã�ͬʱҲ���������Ӧ��λ��
			{
				next_newhead = next_newhead->next;//�ҵ���Ӧ��λ��
			}
			cur_newhead->random = next_newhead;
			cur_newhead = cur_newhead->next;
		}
		cur = cur->next;//�ƶ�����һ���ڵ�

	}
	return newhead;
}

