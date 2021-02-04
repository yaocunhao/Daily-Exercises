//给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。
//注意，要求返回第三大的数，是指第三大且唯一出现的数。
//存在两个值为2的数，它们都排第二。

//解法：
//1.排序的复杂度为NlongN，而遍历一遍数组的时间复杂度为N，因此选择遍历法
//2.注意边界的问题，因此变量的定义用long
//3.定义一个变量count用来计算数组中的重复个数

int thirdMax(int* nums, int numsSize){
	long lable1 = 0;
	long lable2 = 0;
	long lable3 = 0;
	long count = 0;

	for (int i = 0; i<numsSize; i++)
	{
		if ((nums[i] == lable1 || nums[i] == lable2 || nums[i] == lable3) && nums[i] != 0)
			continue;

		if (nums[i]>lable1)//最大值
		{
			if (lable2 != 0)//lable3可能为负数
			{
				lable3 = lable2;
			}
			lable2 = lable1;
			lable1 = nums[i];
			count++;
		}
		else if (nums[i]>lable2)//第二大
		{
			lable3 = lable2;
			lable2 = nums[i];
			count++;
		}
		else if (nums[i]>lable3 || lable3 == 0)
		{
			lable3 = nums[i];
			count++;
		}
	}

	if (numsSize<3 || count<3)
		return lable1;

	return lable3;

}