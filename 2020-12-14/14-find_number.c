#include <stdio.h>
#include <windows.h>
//在一个长度为 n 的数组 nums 里的所有数字都在 0～n - 1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
//

int  com(int *x, int *y)
{
	if (*x>*y)
		return 1;
	else if (*x<*y)
		return -1;
	else
		return 0;
}

int findRepeatNumber(int* nums, int numsSize){
	//先排序，在比较相邻两个
	qsort(nums, numsSize, sizeof(int), com);

	for (int i = 0; i<numsSize - 1; i++)
	{
		if (nums[i] == nums[i + 1])
			return nums[i];
	}
	return nums[0];

}