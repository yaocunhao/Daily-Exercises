// ��ABCD�ĸ����ɷ����϶�����һλ�����֣�������һ��˵�ٻ�
//A��������ɱ�ģ�B��cɱ�ģ�C��Dɱ�ģ�D c˵���Ǽٵ�

#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

void Murderer()
{
	int p[4] = { 0 };//�����ĸ����֣�0�������
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
	printf("������%c\n", i + 'A');
}

int main()
{
	Murderer();
	system("pause");
	return;
}