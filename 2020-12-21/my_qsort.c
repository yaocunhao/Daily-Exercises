#include <stdio.h>
#include <windows.h>
#include <assert.h>
#pragma warning (disable :4996)

typedef struct Stu{
	char name[100];
	char sex[10];
}stu;

void Swap(void *_x, void *_y,int size)
{
	char *x = (char *)_x;
	char *y = (char *)_y;
	char temp = 0;
	while (size)
	{
		temp = *x;
		*x = *y;
		*y = temp;
		x++;
		y++;
		size--;
	}
}
int com(const stu *x,const stu *y)
{
	return (strcmp(x->sex,y->sex));
}
void My_qsort(void *base, int num, int size, int const(*com)(const void*, const void *))
{
	assert(base);
	assert(com);
	char *e = (char *)base;
	for (int i = 0; i < num - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < num - 1 - i; j++)
		{
			if (com(e + j*size, e + (j + 1)*size)>0)//前者大于后者进行交换
			{
				Swap(e + j*size, e + (j + 1)*size,size);
			}
			flag = 1;
		}
		if (!flag)
			break;
	}

}

int main()
{
	stu p[3];
	for (int i = 0; i < 3; i++)
	{
		scanf("%s", p[i].name);
		scanf("%s", p[i].sex);
	}
	for (int i = 0; i < 3; i++)
	{
		printf("姓名：%s", p[i].name);
		printf("性别：%s", p[i].sex);
		printf("\n");
	}
	My_qsort(p, 3, (int)sizeof(p[0]), com);
	for (int i = 0; i < 3; i++)
	{
		printf("after 姓名：%s", p[i].name);
		printf("性别：%s", p[i].sex);
		printf("\n");
	}
	/*int arr[10] = { 12, 15, 15, 11, 22, 61, 125, 15, 15 };
	int num = sizeof(arr) / sizeof(arr[0]);*/
	/*My_qsort(arr,num,sizeof(int ),com);
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}*/

	system("pause");
	return 0;
}