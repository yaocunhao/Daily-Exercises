
ʵ�ֺ���double Power(double base, int exponent)����base��exponent�η�������ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ������⡣

//��Ҫע��߽��ʣ���������Ϊ����ʱת�����ܳ���Խ��
double myPow(double x, int n){
	long base = n;
	if (base<0)
	{
		x = 1 / x;
		base = -base;
	}
	double ret = 1;
	while (base)
	{
		if (base & 1)
			ret *= x;
		x *= x;
		base >>= 1;
	}

	return ret;

}