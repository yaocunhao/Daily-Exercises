给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。


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