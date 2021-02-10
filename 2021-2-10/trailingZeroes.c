//设计一个算法，算出 n 阶乘有多少个尾随零。

//思路：有零则有10,10分为为5和2,2的个数明显比5多，因此只需要统计5的个数

int trailingZeroes(int n){
	int count = 0;
	while (n)
	{
		n /= 5;
		count += n;
	}
	return count;
}