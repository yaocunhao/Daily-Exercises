输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

解题思路
1.求得链表的总长度
2.开辟新数组空间
3.再次遍历链表尾插至新的数组
时间复杂度：O(n), 空间复杂度O(n)

int* reversePrint(struct ListNode* head, int* returnSize){

	int size = 0;
	struct ListNode* newhead = head;
	while (newhead)//求得链表长度
	{
		size++;
		newhead = newhead->next;
	}
	*returnSize = size;
	int *arr = NULL;
	arr = (int *)malloc(sizeof(int)*size);
	while (head)
	{
		arr[size - 1] = head->val;
		head = head->next;
		size--;
	}
	return arr;

}