﻿//给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。
//
//（当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。）


很显然要想达到最大的数，当前面的数大于后面的数的时候，前面的数值-1，后面的数全部变为9


int monotoneIncreasingDigits(int N){
	int k = 1;//每次增长10倍用于每次取两位进行比较，有点像迭代
	int ret = N;
	while (k <= ret / 10)
	{
		int temp = ret / k % 100;//每次取两位，k的作用是递进，temp是保证ret不会被改变
		k *= 10;//递进一位
		if (temp / 10>temp % 10)//前面大于后面
			ret = ret / k*k - 1;//比如165/10*10=160-1=159;
	}
	return ret;

}