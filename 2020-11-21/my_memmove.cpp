#include <stdio.h>
#include <windows.h>
#include <assert.h>
void *my_memmove(void *_str, const void *_scr, int num)
{
	assert(_str&&_scr);
	char *str = (char *)_str+num-1;//��������ǿתΪchar���ͣ�������+1�ƶ�Ϊ1�ֽڣ�
	char *scr = (char *)_scr+num-1;
	
	if (str>scr&&str<(scr + num))//��һ���ص�����scrǰΪ�͵�ַ
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
			num--;//һ�����ֽڽ��н�����ֱ��num���ֽڽ�����ɣ�
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

