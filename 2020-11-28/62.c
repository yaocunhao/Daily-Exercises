#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//ĳ����˾���ù��õ绰�������ݣ���������λ���������ڴ��ݹ������Ǽ��ܵģ����ܹ������£� 
//ÿλ���ֶ�����5,Ȼ���úͳ���10��������������֣��ٽ���һλ�͵���λ�������ڶ�λ�͵���λ������
void Code(int n)
{
	int arr[4] = { 0 };
	int ret = 0;
	arr[0] = (n % 10 + 5) % 10;
	arr[1] = (n / 10 % 10 + 5) % 10;
	arr[2] = (n / 100 % 10 + 5) % 10;
	arr[3] = (n / 1000 + 5) % 10;
	ret = arr[3] + arr[0] * 1000 + arr[1] * 100 + arr[2] * 10;
	printf("�����������Ϊ%d\n", ret);

}

int main()
{
	int n = 0;
	printf("����������\n");
	scanf("%d", &n);
		Code(n);
	system("pause");
	return 0;
}