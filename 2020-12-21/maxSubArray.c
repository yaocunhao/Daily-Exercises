//动态规划；
//题目给出的是子数组的最大和，因此我们不必考虑子数组的长度；
//只需要知道nums[i + 1]和nums[i]的关系即可，如果nums[i]<0, 那么nums[i + 1]不变，否则nums[i + 1] += nums[i];
//这样循环之后我们只需要知道数组中的最大值即可，因此定义一个存储最大值的变量max = nums[0],
//每次循环max都和nums[i + 1]比较一下大小，较大的即保存在max之中



int maxSubArray(int* nums, int numsSize){

	int max = nums[0];
	for (int i = 0; i<numsSize - 1; i++)
	{
		if (nums[i] >= 0)
			nums[i + 1] = nums[i] + nums[i + 1];
		max = max>nums[i + 1] ? max : nums[i + 1];
	}
	return max;

}
