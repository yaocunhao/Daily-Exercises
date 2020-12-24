int com(int *a, int *b)
{
	return *a - *b;
}

bool isStraight(int* nums, int numsSize){
	//排序；再遍历看有没有重复值，如果有直接返回；
	//统计其中鬼王的数量，最大值减最小值<5
	qsort(nums, numsSize, sizeof(int), com);
	int count = 0;//统计鬼王的个数
	for (int i = 0; i<numsSize - 1; i++)
	{
		if (nums[i] == 0)
			count++;
		if (nums[i] == nums[i + 1] && nums[i] != 0)
			return false;
	}
	//到这里排好序且没有重复值
	if (nums[4] - nums[count]<5)
		return true;
	else
		return false;

}
