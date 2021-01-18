给你一个整数 n，请你帮忙计算并返回该整数「各位数字之积」与「各位数字之和」的差。



利用递归求解



int subtractProductAndSum1(int n)
{
	if (n<10)
		return n;

	return (n % 10)*subtractProductAndSum1(n / 10);
}

int subtractProductAndSum2(int n)
{
	if (n<10)
		return n;

	return (n % 10) + subtractProductAndSum2(n / 10);
}


int subtractProductAndSum(int n){
	return
		subtractProductAndSum1(n) - subtractProductAndSum2(n);

}