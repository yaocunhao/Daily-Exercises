//利用栈解决问题，利用先进可以有效的判断左右两侧括号是否对齐
char pairs(char s)
{
	if (s == ')')
		return '(';
	else if (s == '}')
		return '{';
	else if (s == ']')
		return '[';
	else
		return 0;
}

bool isValid(char * s){
	int n = strlen(s);
	if (n % 2 != 0 || n == 0)//长度为奇则，或者为空时直接返回
		return false;

	char skt[n + 1];//构建栈
	int push = 0;
	while (*s)
	{
		if (pairs(*s))//为右括号时进行比较
		{
			if (push == 0 || skt[push - 1] != pairs(*s))//栈为空或者栈内没有对应的符号
				return false;
			else
				push--;
		}
		else
		{
			skt[push] = *s;
			push++;
		}
		s++;

	}
	if (push == 0)//此时栈内为空
		return true;
	else
		return false;
}


