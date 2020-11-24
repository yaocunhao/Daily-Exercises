#include <stdio.h>
#include <windows.h>
//找到年龄最大的人，并输出。请找出程序中有什么问题。
struct man{
	char name[20];
	int  age;
}
person[3] = { "li",5, "wang", 5, "sun",3 };
int main()
{
	struct man *q, *p;
	int i, m = 0;
	p = person;
	q = person;
	for (i = 0; i<3; i++)
	{
		if (m<p->age)
		{
			m = p->age;
			q = p;
		}
		p++;
	}
	for (int i = 0; i < 3; i++)
	{
		if (q[i].age>=m)
		printf("%s %d\n", (q[i]).name, (q[i]).age);
	}
	system("pause");
	return 0;
}