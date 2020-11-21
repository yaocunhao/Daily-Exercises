#include <stdio.h>
#include <windows.h>
#include <assert.h>
void *my_memmove(void *_str, const void *_scr, int num)
{
	assert(_str&&_scr);
	char *str = (char *)_str+num-1;//将空类型强转为char类型，解引用+1移动为1字节；
	char *scr = (char *)_scr+num-1;
	
	if (str>scr&&str<(scr + num))//即一定重叠，且scr前为低地址
	{
		while (num)
		{
			*str = *scr;
			str--;
			scr--;
			num--;
		}
	}
	else
	{
		while (num)
		{
			*str = *scr;
			str++;
			scr++;
			num--;//一个个字节进行交换，直到num个字节交换完成；
		}
	}
	return _str;
}
int main()
{
	char str[] = "abcd123";
	//char scr[] = "qwer521";
	my_memmove(str+1, str, sizeof(str)-2);
	printf("%s\n", str);
	system("pause");
	return 0;
}

