//���һ���㷨����� n �׳��ж��ٸ�β���㡣

//˼·����������10,10��ΪΪ5��2,2�ĸ������Ա�5�࣬���ֻ��Ҫͳ��5�ĸ���

int trailingZeroes(int n){
	int count = 0;
	while (n)
	{
		n /= 5;
		count += n;
	}
	return count;
}