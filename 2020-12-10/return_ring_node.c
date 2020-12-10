#include <stdio.h>
#include <windows.h>


 struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *fun(struct ListNode *head) {
	//���ж��ǲ��ǻ���������ҳ���һ��������λ��
	if (head == NULL || head->next == NULL)
		return NULL;//�ɻ���������
	struct ListNode *slow = head;
	struct ListNode *fast = head;
	while (fast)
	{
		slow = slow->next;
		if (fast->next == NULL)
			return NULL;
		fast = fast->next->next;
		if (slow == fast)//�غ���
			break;
	}
	if (fast == NULL)
		return fast;
	//��ʱ�õ���һ��������λ��
	struct ListNode *dst = head;//��ԭ�㿪ʼ����
	while (1)
	{
		if (dst == slow)
		{
			return dst;
		}
		dst = dst->next;
		slow = slow->next;
	}
}

int main()
{
	struct ListNode *n1 = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *n2 = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *n3 = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *n4 = (struct ListNode *)malloc(sizeof(struct ListNode));
	n1->val = 3;
	n2->val = 2;
	//n3->val = 0;
	//n4->val = -4;
	n1->next = n2;
	n2->next = NULL;
	//n3->next = n4;
	//n4->next = n2;

	printf("%d\n",fun(n1));
	system("pause");
	return 0;
}