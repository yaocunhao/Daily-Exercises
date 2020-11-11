// 有ABCD四个嫌疑犯，肯定其中一位是凶手，当中有一人说假话
//A：不是我杀的；B是c杀的；C是D杀的，D c说的是假的

#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

void Murderer()
{
	int p[4] = { 0 };//定义四个凶手，0代表无罪；
	int i = 0;
	for (i = 0;i < 4; i++)
	{
		p[i] = 1;
		if (((p[0] == 0) + (p[2] == 1) + (p[3] == 1) + (p[3] == 0)) == 3)
		{
			break;
		}
		else
			p[i] = 0;
	}
	printf("凶手是%c\n", i + 'A');
}

int main()
{
	Murderer();
	system("pause");
	return;
}