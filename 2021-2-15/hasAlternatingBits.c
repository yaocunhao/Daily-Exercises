//给定一个正整数，检查它的二进制表示是否总是 0、1 交替出现：
//换句话说，就是二进制表示中相邻两位的数字永不相同。

//思路：通过循环N交替缩小2倍，判断间隔的二进制是否相等即可

bool hasAlternatingBits(int n){

	while (n)
	{
		int first = n % 2;
		n = n / 2;
		int second = n % 2;

		if (first == second)
			return false;
	}
	return true;

}