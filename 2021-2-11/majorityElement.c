//数组中占比超过一半的元素称之为主要元素。给定一个整数数组，找到它的主要元素。若没有，返回 - 1。

int majorityElement(int* nums, int numsSize) {
	int index = 0, number = nums[0], i;
	for (i = 0; i<numsSize; i++)
	{
		if (nums[i] == number)index++;
		else index--;
		if (index == 0)number = nums[i + 1];
	}
	index = 0;
	for (i = 0; i<numsSize; i++)
	{
		if (nums[i] == number)index++;
	}
	return index>numsSize / 2 ? number : -1;
}
