//����ջ������⣬�����Ƚ�������Ч���ж��������������Ƿ����
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
	if (n % 2 != 0 || n == 0)//����Ϊ���򣬻���Ϊ��ʱֱ�ӷ���
		return false;

	char skt[n + 1];//����ջ
	int push = 0;
	while (*s)
	{
		if (pairs(*s))//Ϊ������ʱ���бȽ�
		{
			if (push == 0 || skt[push - 1] != pairs(*s))//ջΪ�ջ���ջ��û�ж�Ӧ�ķ���
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
	if (push == 0)//��ʱջ��Ϊ��
		return true;
	else
		return false;
}


