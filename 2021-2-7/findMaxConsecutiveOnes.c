//给定一个二进制数组， 计算其中最大连续1的个数。

//思路：遍历数组，给一个计数器 ，一个返回值变量，如果计数器的值大于返回变量
//则赋值给返回变量，如果遇到0则计数器归零，

int findMaxConsecutiveOnes(int* nums, int numsSize){
	int max = 0;
	int count = 0;
	for (int i = 0; i<numsSize; i++)
	{
		if (nums[i] == 1)
			count++;
		if (count>max)
			max = count;
		if (nums[i] == 0)
			count = 0;//归零
	}
	return max;

}