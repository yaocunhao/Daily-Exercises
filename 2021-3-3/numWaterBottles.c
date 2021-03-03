//小区便利店正在促销，用 numExchange 个空酒瓶可以兑换一瓶新酒。你购入了 numBottles 瓶酒。
//
//如果喝掉了酒瓶中的酒，那么酒瓶就会变成空的。
//
//请你计算 最多 能喝到多少瓶酒。


int numWaterBottles(int numBottles, int numExchange){
	int ret = numBottles;
	int empty = numBottles;//空瓶子数

	while (empty >= numExchange)//空瓶子大于可以兑换就可以继续喝
	{
		ret += 1;
		empty = empty - numExchange + 1;
	}
	return ret;

}

