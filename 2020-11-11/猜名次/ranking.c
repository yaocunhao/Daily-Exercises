//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
//A选手说：B第二，我第三；B选手说：我第二，E第四；C选手说：我第一，D第二；D选手说：C最后，我第三；
//E选手说：我第四，A第一；比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

char Judge(int *p)//判断是名次否重复
{
	char t = 0;
	for (int i = 0; i < 5; i++)
	{
		t |= 1 << p[i];
	}
	return t == 0x3e;
}

void Ranking(int *p,int n)
{
	if (n >= 5)
	{
		if (((p[1] == 2) + (p[0] == 3) == 1) && ((p[1] == 2) + (p[4] == 4) == 1)\
			&& ((p[2] == 1) + (p[3] == 2) == 1) && ((p[2] == 5) + (p[3] == 3) == 1)\
			&& ((p[4] == 4) + (p[0] == 1) == 1) && Judge(p))
		{
			for (int i = 0; i < 5; i++)
			{
				printf("%c选手的名次是%d\n", i + 'A', p[i]);
			}
		}
		return;
	}
	for (p[n] = 1; p[n] < 6; p[n]++) //需要遍历5x5次，用递归代码更简洁；
	{
		Ranking(p,n+1);
	}
}

int main()
{
	int p[5];
	Ranking(p,0);
	system("pause");
	return;	
}
