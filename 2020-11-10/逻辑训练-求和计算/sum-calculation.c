#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)
void Sum()
{
	int x = 0;
	scanf("%d", &x);
	int result = 0;
	int t = 0;
	for (int i = 0; i < 5; i++)
	{
		t = t* 10 + x;
		result += t;
	}
	printf("%d\n", result);
}

int main()
{
	Sum();
    system("pause");
	return 0;
}
