#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#pragma warning (disable:4996)
//ģ��ʵ��qsort
void swap(void *_x, void *_y,size_t size)
{
	char *x = (char*)_x;//void*ֻ����������ָ�룬�������Ͳ���ȷ���ܽ����ã�
	char *y = (char*)_y;
	char temp = 0;
	while (size)//��ÿ���ֽڵ����ݽ��н�����һֱ��������Ԫ�ش�Сsize���ֽڽ������Ϊֹ
	{
	    temp = *x;
		*x = *y;
		*y = temp;
		x++;
		y++;
		size--;
	}
}
//int Comp(const void *_x,const void *_y)//��������������һ��������Ԫ�صĵ�ַ
//{
//	int *x = (int *)_x;//void���ܽ�����
//	int *y = (int *)_y;
//	if (*x > *y)
//	{
//		return 1;
//	}
//	else if (*x < *y)
//	{
//		return -1;
//	}
//	else
//		return 0;
//}

//void Prin(int arr[],int num)
//{
//	for (int i = 0; i < num; i++){
//		printf("%d\n", arr[i]);
//	}
//}


int  Comp(const void *_x, const void *_y)
{
	char *x = *(char **)_x;
	char *y = *(char **)_y;
	return strcmp(x, y);
}

void Prin(const char **str, int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%s\n", str[i]);
	}
}
void MyQsort(void *arr, int num, size_t size,int (*Comp)(const void *, const void *))
{
	assert(arr!= NULL);	
	assert(Comp != NULL);
	char *e = (char *)arr;//void ���Ͳ���ȷ����ָ��Ӽ�ʱ�޷��жϲ������⣻
	for (int i = 0; i < num - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < num - 1 - i; j++)
		{
			if(Comp(e+j*size,e+(j+1)*size)>0)//arrǿת��char��ÿ���ƶ�һ���ֽڣ�������Ҫ���϶�Ӧ��Ԫ�ش�Сsize
			{
				swap(e + j*size, e + (j + 1)*size,size);
				flag = 1;
			}
		}
		if (flag==0)
		{
			break;//��û�н���ð��ѭ��ʱ��ֹͣ��
		}
	}
}
int main()
{
	//int arr[] = { 343, 445, 4, 53, 32, 43, 5, 434, };
	//int num = sizeof(arr) / sizeof(arr[0]);
	//MyQsort(arr, num, sizeof(int),Comp);
	//Prin(arr, num);
	char *str[] = { "fdfd", "ddsd", "adsa", "bfdfd" };
	int num = sizeof(str) / sizeof(str[0]);
	MyQsort(str, num, sizeof(char*), Comp);
	Prin(str, num);
	system("pause");
	return 0;

}