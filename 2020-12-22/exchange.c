#include <stdio.h>
#include <windows.h>


int* exchange(int* nums, int numsSize){
	//ע���ж���������������if�жϲ��ܷ��ڵ�һ���жϵ�ǰ�棻
	//ͷβָ�뷨��������ǰ���ָ���ҵ�ż���������ָ���ҵ�������ͣ�������ڽ��н��������
		//���������жϷ���ǰ�棬�����ѽ������˸ı䣬��Ӧ�Ĳ����ǵ�ǰ�±��Ԫ�أ�

	int start = 0;
	int end = numsSize - 1;
	while (start < end)
	{
		if ((nums[start] % 2 == 0) && (nums[end] % 2 != 0))
		{
			int temp = nums[start];
			nums[start] = nums[end];
			nums[end] = temp;
		}
		if (nums[start] % 2 != 0)
			start++;
		if (nums[end] % 2 == 0)
			end--;
	}
}

int main()
{
	int arr[] = { 1,11,14};
	int size = sizeof(arr) / sizeof(arr[0]);
	exchange(arr,size);
	for (int i = 0; i < size; i++)
	{
		printf("%d\n", arr[i]);
	}
	system("pause");
	return 0;
}