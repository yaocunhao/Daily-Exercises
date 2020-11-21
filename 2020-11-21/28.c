#include <stdio.h>
#include <windows.h>
//有5个人坐在一起，问第五个人多少岁？他说比第4个人大2岁。问第4个人岁数，他说比第3个人大2岁。
//问第三个人，又说比第2人大两岁。问第2个人，说比第一个人大两岁。最后问第一个人，他说是10岁。请问第五个人多大？

int FiveAge(int num)
{
	if (num == 1)
		return 10;
	return 2 + FiveAge(num - 1);
}

int main()
{
	int age=FiveAge(5);
	printf("%d\n", age);
	system("pause");
	return 0;
}