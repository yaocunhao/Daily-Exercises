//�����������ֵĵ���������Ч�ʱȵݹ�Ҫ�ߣ�

int fib(int n){
	int first = 1;
	int second = 0;
	int third = 0;
	while (n)
	{
		third = ((first + second) % 1000000007);
		first = second;
		second = third;
		n--;
	}
	return third;

}

