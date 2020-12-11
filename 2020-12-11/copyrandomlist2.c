//拷贝老节点插在新节点后面，最后形成两倍长度的新链表
//再利用相对位置的关系，将新链表分离出来
struct Node* copyRandomList(struct Node* head) {
	if (head == NULL)
		return head;
	struct Node *cur = head;
	while (cur)
	{
		struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
		//将新节点复制老节点，并且插在新节点后边
		temp->val = cur->val;
		temp->next = cur->next;
		temp->random = cur->random;
		cur->next = temp;
		cur = temp->next;
	}
	//此时已经完成链表的拷贝，新的链表为新旧形成的长链表
	cur = head->next;//得到新链表的头
	struct Node *newhead = cur;//保存新链表的头；
	while (cur)
	{
		if (cur->random != NULL)
			cur->random = cur->random->next;//新的节点永远在老链表的下一个；
		if (cur->next != NULL)
			cur->next = cur->next->next;
		cur = cur->next;//移动到下一个新的节点
	}
	return newhead;