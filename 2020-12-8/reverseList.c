//反转链表
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* reverseList(struct ListNode* head){
	if (head == NULL || head->next == NULL)//为空或者只有1个
		return head;
	struct ListNode *prev = NULL, *cur = head, *next = head->next;
	while (cur != NULL)
	{
		cur->next = prev;//进行反转
		//进行迭代移动
		prev = cur;
		cur = next;
		if (next)//注意边界
			next = next->next;
	}
	return prev;
}