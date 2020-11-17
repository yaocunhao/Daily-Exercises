#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#pragma warning (disable:4996)
//模拟实现qsort
void swap(void *_x, void *_y,size_t size)
{
	char *x = (char*)_x;//void*只是用来接收指针，但是类型不明确不能解引用；
	char *y = (char*)_y;
	char temp = 0;
	while (size)//将每个字节的内容进行交换，一直到将整个元素大小size个字节交换完成为止
	{
	    temp = *x;
		*x = *y;
		*y = temp;
		x++;
		y++;
		size--;
	}
}
//int Comp(const void *_x,const void *_y)//传进来的是任意一个待排序元素的地址
//{
//	int *x = (int *)_x;//void不能解引用
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
	char *e = (char *)arr;//void 类型不明确，对指针加减时无法判断步伐问题；
	for (int i = 0; i < num - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < num - 1 - i; j++)
		{
			if(Comp(e+j*size,e+(j+1)*size)>0)//arr强转成char后每次移动一个字节，所以需要乘上对应的元素大小size
			{
				swap(e + j*size, e + (j + 1)*size,size);
				flag = 1;
			}
		}
		if (flag==0)
		{
			break;//当没有进入冒泡循环时就停止；
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