#include <stdio.h>
#include <windows.h>
//����nums������0��n������������������ȱ��һ�������д�����ҳ��Ǹ�ȱʧ�����������а취��O(n)ʱ���������
int FindNum(int arr[],int num)
{
	int count = 0;
	int ret = 0;
	for (int i = 0; i < num; i++)
	{
		ret += i;
		count += arr[i];
	}
	return (ret + num - count);

}

int main()
{
	int arr[] = { 0,1,2,3,4,8,6,7};
	int num = sizeof(arr) / sizeof(arr[0]);
	int ret=FindNum(arr, num);
	printf("%d\n", ret);
	system("pause");
	return 0;
}