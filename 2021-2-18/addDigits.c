����һ���Ǹ����� num������������λ�ϵ�������ӣ�ֱ�����Ϊһλ����


int addDigits(int num){
	if (num<10)
		return num;
	int sum = 0;
	while (num)
	{
		sum += num % 10;
		num /= 10;
		if (sum<10 && num == 0)
			break;
		if (sum >= 10 && num == 0)
		{
			num = sum;
			sum = 0;
		}
	}
	return sum;

}