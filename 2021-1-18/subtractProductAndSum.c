����һ������ n�������æ���㲢���ظ���������λ����֮�����롸��λ����֮�͡��Ĳ



���õݹ����



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