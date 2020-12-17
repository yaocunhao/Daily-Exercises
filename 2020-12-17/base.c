
实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。

//需要注意边界问，测试用例为负数时转换可能出现越界
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