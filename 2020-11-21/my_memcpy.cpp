#include <stdio.h>
#include <windows.h>
#include <assert.h>
void *my_memcpy(void *_str, const void *_scr, int num)
{
	assert(_str&&_scr);
	char *str = (char *)_str;//��������ǿתΪchar���ͣ�������+1�ƶ�Ϊ1�ֽڣ�
	char *scr = (char *)_scr;
	while (num)
	{
		*str = *scr;
		str++;
		scr++;
		num--;//һ�����ֽڽ��н�����ֱ��num���ֽڽ�����ɣ�
	}
	return _str;
}
int main()
{
	char str[] = "abcd123";
    char scr[] = "qwer521";
	my_memcpy(str,scr, sizeof(scr));
	printf("%s\n", str);
	system("pause");
	return 0;
}

