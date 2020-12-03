//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

//保证base和exponent不同时为0
class Solution {
public:
	double Power(double base, int exponent) {
		double t = 1;
		if (base == 0)
			return 0;
		else if (exponent == 0)
			return 1;
		else
		{
			int e = exponent;
			if (e<0)
				e *= (-1);
			while (e)
			{
				if (e)
				{
					t *= base;
				}
				e >>= 1;
				base *= base;
			}
			if (exponent<0)
				return (1 / t);
			else
				return t;
		}

	}
};
//class Solution {
//public:
//	double Power(double base, int exponent) {
//		double t = 1;
//		if (base == 0)
//			return 0;
//		if (exponent == 0)
//			return 1;
//		if (exponent>0)
//		{
//			while (exponent)
//			{
//				t *= base;
//				exponent--;
//			}
//			return t;
//		}
//		else
//		{
//			while (exponent)
//			{
//				t *= base;
//				exponent++;
//			}
//			return (1 / t);
//		}
//	}
//};

