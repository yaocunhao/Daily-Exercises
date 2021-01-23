#include <stdio.h>
#include <windows.h>

int  isAnagram(char s[], char t[]){

	while (*s&&*t)//前面的都不相同
	{
		if (((*s)++) == ((*t)++))
			break;;
	}

	while (*s || *t)//后面的都相同
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
		printf("有效\n");
	else
		printf("无效\n");

	system("pause");
	return 0;
}