#include<stdio.h>
#include <windows.h>
#pragma warning (disable:4996)
#include <string.h>

//ÊäÈë i like beijing. Êä³ö beijing. like i
void Reverse_string(char *left,char *right)
{
	char temp = 0;
	while (left < right)
	{
		temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}
int main()
{
	char str[60] = { 0 };
	fgets(str, sizeof(str) - 1, stdin);
	str[strlen(str) - 1] = '\0';
	char *left = str;
	char *right = str;
	while (*right != '\0')
	{
		while (*right != ' '&&*right != '\0')
		{
			right++;
		}
		Reverse_string(left,right-1);
		if (right != '\0');
		right++;
		left = right;
	}	
	Reverse_string(str,str+strlen(str)-1);
	printf("%s", str);
	system("pause");
	return 0;
}