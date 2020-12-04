#include "seqlist.h"

void Menu()
{
	printf("############################################\n");
	printf("#1.打印 ##############################2.尾插\n");
	printf("#3.尾删###############################4.首插\n");
	printf("#5.首删###############################6.查找\n");
	printf("#7.在任意位置插入#############8.删除某个位置\n");
	printf("#9.销毁顺序表################10.退出########\n");
	printf("############################################\n");

}
void SeqListInit(SL*sp)//开辟空间
{
	assert(sp);
	sp->arr = (SLDataType*)malloc(sizeof(SLDataType)* 4);
	if (sp->arr == NULL)
	{
		printf("开辟空间失败\n");
		exit(-1);
	}
	printf("开辟空间成功\n");
	sp->size = 0;
	sp->capacity = 4;
}
void SeqListPrint(SL*sp)//打印
{
	assert(sp);
	if (sp->size == 0)
	{
		printf("内容为空\n");
	}
	for (int i = 0; i < sp->size; i++)
	{
		printf("%d\n", sp->arr[i]);
	}
}
void static CheckCapacity(SL*sp)//检查容量
{
	assert(sp);
	if (sp->size == sp->capacity)
	{
		SLDataType *p = (SLDataType*)realloc(sp->arr, 2 * sp->capacity);
		if (p == NULL)
		{
			printf("扩容失败\n");
		}
		else
			sp->arr = p;
		sp->capacity = 2 * sp->capacity;
	}
}
void SeqListPushBack(SL*sp)//尾插
{
	assert(sp);
	int n = 0;
	CheckCapacity(sp);
	printf("请输入你要插入的数据\n");
	scanf("%d", &n);
	sp->arr[sp->size] = n;
	sp->size++;
}
void SeqListPopBack(SL*sp)//尾删
{
	assert(sp);
	sp->size--;
}
void SeqListPushFront(SL*sp)//首插
{
	assert(sp);
	int n = 0;
	CheckCapacity(sp);
	int end = sp->size;
	while (end)
	{
		sp->arr[end] = sp->arr[end-1];
		end--;
	}
	printf("请输入你要插入的数据\n");
	scanf("%d", &n);
	sp->arr[0]=n;
	sp->size++;

}
void SeqListPopFront(SL*sp)//首删
{
	assert(sp);
	for (int i = 0; i < sp->size - 1; i++)
	{
		sp->arr[i] = sp->arr[i + 1];
	}
	sp->size--;
}
void SeqListFind(SL*sp)//查找
{
	assert(sp);
	int n = 0;
	printf("请输入你要查找的数字\n");
	scanf("%d", &n);
	for (int i = 0; i < sp->size; i++)
	{
		if (sp->arr[i] == n)
		{
			printf("%d在顺序表中对应的下标是%d\n", n, i);
			break;
		}
	}
	printf("顺序表中没有你要查找的数字\n");
}
void SeqListInsert(SL*sp)//任意插入
{
	assert(sp);
	CheckCapacity(sp);
	int pos = 0;
	int n = 0;
	printf("请输入你要在哪个位置插入什么数字\n");
	scanf("%d%d", &pos, &n);
	if (pos > sp->size)
		printf("输入有误\n");
	else
	{
		int end = sp->size;
		while (end > (pos - 1))//位置比下标大1
		{
			sp->arr[end] = sp->arr[end - 1];
			end--;
		}
		sp->arr[pos - 1] = n;

		sp->size++;
	}
}
void SeqListErase(SL*sp)//删除位置的值
{
	assert(sp);
	int pos = 0;
	printf("请输入你要删除哪个位置的值\n");
	scanf("%d", &pos);
	if (pos > sp->size)
	{
		printf("输入有误\n");
	}
	else
	{
		for (int i = pos - 1; i < sp->size - 1; i++)
		{
			sp->arr[i] = sp->arr[i + 1];
		}
		sp->size--;
	}
}
void SeqListDestory(SL*sp)//销毁顺序表
{
	assert(sp);
	if (sp->capacity == 0)
	{
		printf("已经销毁，禁止重复操作\n");
	}
	else
	{
		free(sp->arr);
		sp->size = 0;
		sp->capacity = 0;
	}
}

