//数组中占比超过一半的元素称之为主要元素。给定一个整数数组，找到它的主要元素。若没有，返回 - 1。

//思路：利用摩尔投票法，寻找到数组中的众数，再统计该众数出现的次数，然后进行比较，该众数是否
//超过了数组的一半

int majorityElement(int* nums, int numsSize) {
	int index = 0, number = nums[0], i;
	//遍历第一遍，找到众数
	for (i = 0; i<numsSize; i++)
	{
		if (nums[i] == number)
			index++;
		else
			index--;
		if (index == 0)//重新确定众数
			number = nums[i + 1];
	}
	//进行判断，众数个数是否超过数组个数的一半
	index = 0;
	for (i = 0; i<numsSize; i++)
	{
		if (nums[i] == number)
			index++;
	}
	return index>numsSize / 2 ? number : -1;
}
