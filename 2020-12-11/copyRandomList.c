//**思路分析**
//既然是深度拷贝，原链表有多少个节点我们就开辟多少个节点，将原节点内容拷贝到新列表节点，然后新链表自我串联，就只剩下随机指针没有填入了，这时利用循环，得到老链表中各个节点的随机指针指向的位置，再用这个位置去新链表中进行寻找，这样就完成了深度拷贝；


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
	struct Node *newhead = (struct Node*)malloc(sizeof(struct Node));//开辟新节点
	struct Node *node = head;//head的地址后面还要用到
	newhead->val = head->val;//拷贝内容
	newhead->next = NULL;
	node = node->next;
	struct Node *tail = newhead;
	while (node)//开辟N个节点将链表的N个节点的内容拷贝过去
	{
		struct Node *temp = (struct Node*)malloc(sizeof(struct Node));//开辟节点装原链表的值
		temp->val = node->val;//拷贝内容
		temp->next = NULL;
		tail->next = temp;//进行尾插
		tail = tail->next;
		node = node->next;
	}
	//上面完成了新链表的深拷贝，只缺少random_index，下面进行random_index的填写

	struct Node *cur_newhead = newhead;
	struct Node *cur = head;
	while (cur)
	{
		int count = 0;//计数器
		struct Node *next_newhead = newhead;
		struct Node *next = head;//这两个语句是用来寻找对应位置的，循环一次重置一次
		while (next)//next为空说明没有找到
		{
			if (cur->random == next)//找到随机指针的地址
				break;
			count++;
			next = next->next;//后移
		}
		if (next == NULL)//随机指针为空
		{
			cur_newhead->random = NULL;
			cur_newhead = cur_newhead->next;//到下一个节点继填写
		}
		else
		{
			while (count--)//count老链表对应的位置，新链表是老链表拷贝过来得，同时也是新链表对应的位置
			{
				next_newhead = next_newhead->next;//找到对应的位置
			}
			cur_newhead->random = next_newhead;
			cur_newhead = cur_newhead->next;
		}
		cur = cur->next;//移动到下一个节点

	}
	return newhead;
}

