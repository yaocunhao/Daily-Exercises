#include <stdio.h>
#include <windows.h>

int  isAnagram(char s[], char t[]){

	while (*s&&*t)//ǰ��Ķ�����ͬ
	{
		if (((*s)++) == ((*t)++))
			break;;
	}

	while (*s || *t)//����Ķ���ͬ
	{
		if (((*s)++) != ((*t)++))
			return 0;
	}
	return 1;
}
int main()
{

	char s[] = "anagram";
	char t[] = "nagaram";



	if (isAnagram(s, t))
		printf("��Ч\n");
	else
		printf("��Ч\n");

	system("pause");
	return 0;
}