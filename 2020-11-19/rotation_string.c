#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
 void Splicing(char spl[])
{
	strncat(spl, spl,strlen(spl));//进行拼接
}
int main()
{
	char str[64];
	char dst[64];
	char spl[64];
	printf("请输入原字符串\n");
	gets(str);
	strcpy(spl,str);//拷贝字符串
	Splicing(spl);
	printf("请输入原需要比较的字符串\n");
	gets(dst);
	char *p = strstr(spl, dst);//查找字串，找不到返回值为空
	if (p!=NULL)
	{
		printf("%s是%s旋转之后的字符串\n",dst,str);
	}
	else
		printf("%s不是%s旋转之后的字符串\n", dst, str);
	

	
	system("pause");
	return 0;
}