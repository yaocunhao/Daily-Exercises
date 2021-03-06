//求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

//解题方法：通过类每次创建对象都要调用析构函数来完成，定义两个static成员变量，来完成即可
//需要注意：牛客网上都是多组测试用例，static不会自动清零，因此需要多写一个变量清零函数

class Sum
{
public:
	Sum()
	{
		_ret += _i;
		_i++;
	}
	static void BlackZero()//由于是多组测试用例，因此要将静态变量清零
	{
		_i = 1;
		_ret = 0;
	}
	static int GetRet()
	{
		return _ret;
	}

private:
	static int _i;
	static int _ret;
};
int Sum::_i = 1;
int Sum::_ret = 0;

class Solution {
public:
	int Sum_Solution(int n) {
		Sum().BlackZero();
		Sum arr[n];

		int ret = Sum::GetRet();
		return ret;

	}
};