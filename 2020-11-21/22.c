#include <stdio.h>
#include <windows.h>
//两个乒乓球队进行比赛，各出三人。甲队为a，b，c三人，乙队为x，y，z三人。
//已抽签决定比赛名单。有人向队员打听比赛的名单.a说他不和x比，c说他不和x，z比，请编程序找出三队赛手的名单。
void Roll()
{
	char i = 0;
	char j = 0;
	char k = 0;
	for (i = 'x'; i <= 'z';i++)
	{
		for (j = 'x'; j <= 'z'; j++)
		{
			if (i != j)
			{
				for (k = 'x'; k <= 'z'; k++)
				{
					if (j != k&&i!= k)//3个if判断使得ijk为abc的随机排列组合
					{
						if (i != 'x'&&k!='x'&&k!='z')
							printf("a--%c,b--%c,c--%c",i,j,k);
					}
				}
			}
		}
	}
}
int main()
{
    Roll();
	system("pause");
	return 0;
}