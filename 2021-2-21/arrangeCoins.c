//你总共有 n 枚硬币，你需要将它们摆成一个阶梯形状，第 k 行就必须正好有 k 枚硬币。
//
//给定一个数字 n，找出可形成完整阶梯行的总行数。
//
//n 是一个非负整数，并且在32位有符号整型的范围内。
//

//思路：利用等差数列公式，n = na1 + n(n - 1)d / 2;


int arrangeCoins(int n){
	double x = 0;
	double count = 0;
	while (1)
	{
		x = count + count / 2 * (count - 1);
		count++;
		if (x == n)
			return (int)(count - 1);

		if (x>n)
			return (int)(count - 2);
	}

}