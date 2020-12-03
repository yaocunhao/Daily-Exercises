//写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号

class Solution {
public:
	int Add(int num1, int num2)
	{
		int count = 0;
		if (num2 >= 0)
		{
			while (count != num2)
			{
				num1++;
				count++;
			}
			return num1;
		}
		else
		{
			count = (num2*(-1));
			while (count)
			{
				num1--;
				count--;
			}
			return num1;
		}

	}
};