//给你一个由若干 0 和 1 组成的数组 nums 以及整数 k。如果所有 1 都至少相隔 k 个元素，
//则返回 True ；否则，返回 False 。

//思路：遍历数组，先找到第一个1，然后计数器变量归零，再统计两个1之间间隔的0的个数

bool kLengthApart(int* nums, int numsSize, int k){
	int lable = -1;
	for (int i = 0; i<numsSize; i++)
	{
		if (nums[i] == 1)//归零
		{
			if (lable<k&&lable != -1)//已经开始统计
				return false;
			lable = 0;
		}
		else
		{
			if (lable != -1)//检查是否遇到第一个1
				lable++;
		}
	}
	return true;
}