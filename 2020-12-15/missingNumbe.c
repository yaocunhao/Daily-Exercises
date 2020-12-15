数组是有序递增且不重复出现，那么假设我们第一次取中间点mid，如果数组没有缺失元素
nums[mid]一定等于mid，但是缺失了元素后就不一定相等了；
如果相等，说明前半部分是有序的这时候我们将区间缩小，left = mid + 1；
如果不相等说明缺失的数字处于前半部分，此时right = mid - 1;
直至循环停止，此时left的值就是对应的缺失的数字
int missingNumber(int* nums, int numsSize){
	int left = 0;
	int right = numsSize - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (nums[mid] == mid)//左边是有序
			left = mid + 1;
		else//左边是无序的
			right = mid - 1;
	}
	return left;

}