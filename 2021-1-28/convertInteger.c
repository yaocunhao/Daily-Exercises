整数转换。编写一个函数，确定需要改变几个位才能将整数A转成整数B。

int convertInteger(int A, int B){
	//判断A和B的二进制中的位有几个不同，和异或性质相同
	unsigned int c = A^B;//注意越界
	int ret = 0;
	while (c)
	{
		c = c&(c - 1);//每次消除一个1
		ret += 1;
	}
	return ret;
}