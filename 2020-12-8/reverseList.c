//��ת����
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* reverseList(struct ListNode* head){
	if (head == NULL || head->next == NULL)//Ϊ�ջ���ֻ��1��
		return head;
	struct ListNode *prev = NULL, *cur = head, *next = head->next;
	while (cur != NULL)
	{
		cur->next = prev;//���з�ת
		//���е����ƶ�
		prev = cur;
		cur = next;
		if (next)//ע��߽�
			next = next->next;
	}
	return prev;
}