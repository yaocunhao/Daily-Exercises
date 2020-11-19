#include <stdio.h>
#include <windows.h>
#pragma warning(disable :4996)
//实现一个函数，可以左旋字符串中的k个字符。
//思路：先截取第K个位置，再拼接K个字母

int main()
{
	char str[64];
	char dst[64];
	int k = 0;
	printf("请输入需要左旋的字符串\n");
		scanf("%s", str);
		printf("请输入需要左旋几个字符\n");
			scanf("%d", &k);
			strcpy(dst, (str + k));//截取第K个位置
			strncat(dst, str, k);//拼接K个字母
			printf("左旋之前的字符串是%s,左旋%d个字符后的字符串是%s", str, k, dst);
	system("pause");
	return 0;
}