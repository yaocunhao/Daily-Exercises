����һ�������ͷ�ڵ㣬��β��ͷ����������ÿ���ڵ��ֵ�������鷵�أ���

����˼·
1.���������ܳ���
2.����������ռ�
3.�ٴα�������β�����µ�����
ʱ�临�Ӷȣ�O(n), �ռ临�Ӷ�O(n)

int* reversePrint(struct ListNode* head, int* returnSize){

	int size = 0;
	struct ListNode* newhead = head;
	while (newhead)//���������
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