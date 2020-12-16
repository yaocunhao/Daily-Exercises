山脉数组，根据题意即是一个左升右降的数组，二分查找的条件是数组是有序的，因此我们需要找到数组的山脉的至高点即数组的最大数，很显然我们可以利用二分查找来完成这个动作。
设左边界为left，右边界为right，中间点为mid；
当nums[mid]>nums[mid - 1]的时候，此时mid为山顶或者左边升序数组中间，因此left = mid，为什么不是mid + 1呢，因为mid有可能是山顶，如果mid + 1即错过了这个值；
同理当nums[mid]>nums[mid + 1]，mid位于山顶或者右边降序数组之间，因此right = mid；
直至循环结束即left = right，此时即为山顶；

int findInMountainArray(int target, MountainArray* mountainArr) {
	int left = 0;
	int right = length(mountainArr) - 1;

	while (left<right)//找到山顶
	{
		int mid = left + (right - left) / 2;
		if (get(mountainArr, mid)>get(mountainArr, mid - 1))
			left = mid;
		if (get(mountainArr, mid)>get(mountainArr, mid + 1))//在右侧
			right = mid;
	}

	//左侧升序数组
	int newleft = 0;
	int newright = length(mountainArr) - 1;
	while (newleft <= left)
	{
		int mid = newleft + (left - newleft) / 2;
		if (get(mountainArr, mid)<target)
			newleft = mid + 1;
		else if (get(mountainArr, mid)>target)
			left = mid - 1;
		else
			return mid;
	}

	//右侧降序数组
	while (right <= newright)
	{
		int mid = right + (newright - right) / 2;
		if (get(mountainArr, mid)>target)
			right = mid + 1;
		else if (get(mountainArr, mid)<target)
			newright = mid - 1;
		else
			return mid;
	}
	return -1;
}