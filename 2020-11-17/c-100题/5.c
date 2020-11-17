
//输入三个数，从小到大输出

#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)

void Comp(int x,int y,int z)
{
	int t = 0;
	if (x > y)
	{
		t = x;
		x = y;
		y = t;
	}
	if (x > z)
	{
		t = x;
		x = z;
		z = t;
	}
	if (y> z)
	{
		t = y;
		y = z;
		z = t;
	}
	printf("从小到大排列为%d %d %d", x, y, z);
}
int main()
{
	int x=0;
	int y=0;
	int z=0;
	printf("请输入三个数字\n");
	scanf("%d %d %d", &x, &y, &z);
	Comp(x, y, z);
	system("pause");
	return 0;

}