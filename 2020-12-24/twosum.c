int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int *arr = (int *)malloc(sizeof(int)* 2);
	int left = 0, right = numsSize - 1;
	while (left <= right)
	{
		if (nums[left] + nums[right]<target)
			left++;
		else if (nums[left] + nums[right]>target)
			right--;
		else
		{
			*returnSize = 2;
			arr[0] = nums[left];
			arr[1] = nums[right];
			return arr;
		}
	}
	*returnSize = 0;
	return nums;
}