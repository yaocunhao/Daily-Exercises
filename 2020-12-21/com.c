//数组中出现次数超过一半的数字
//方法1：排序找中位数
//
//int com(int *x, int *y)
//{
//	return (*x - *y);
//}
//int majorityElement(int* nums, int numsSize){
//
//	qsort(nums, numsSize, sizeof(int), com);
//	return nums[numsSize / 2];
//
//}

//，摩尔投票法	
int majorityElement(int* nums, int numsSize){
	int value = 0;
	int count = 0;
	for (int i = 0; i<numsSize; i++)
	{
		if (count == 0)
			value = nums[i];//每次取1个元素
		if (value == nums[i])
			count++;
		else
			count--;
	}
	return value;
}

