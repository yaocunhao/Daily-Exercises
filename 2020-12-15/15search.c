//看到查找数组中的数字的次数，下意识就要反应二分查找；
//假设数组中有我们查找的值target，并且有多个，这时候就不能用普通的二分查找来进行了，
//这多个目标值肯定是连在一起的，因此我们需要找到这几个连在一起的起始坐标和终止坐标，他们的差值就是我们
//需要目标值的个数(注意边界，不同的做法差值不一定正好))，我采用的做法是先找到目标值的右边边界即
//nums[right - 1] = target，再寻找
//target - 1的右边边界，即nums[right] = target，因此两个相减就为目标值的个数；
//当寻找第一次右边界的时候，我们可以通过第一次的边界判断是否存在目标值；
//如果 第一次寻找的目标值 target <= 0 || target >= numsSize，那么数组之中不存在目标值，
//此时直接返回0，不再进行第二次查找；
int Binearch(int *nums, int numsSize, int target)//封装一个右边界二分查找
{
	int left = 0;
	int right = numsSize - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (target<nums[mid])
			right = mid - 1;
		else if (target>nums[mid])
			left = mid + 1;
		else//找到了
			left = mid + 1;
	}
	return left;//返回右边界点
}

int search(int* nums, int numsSize, int target){
	int R_right = Binearch(nums, numsSize, target);//找到第一个右边界点
	if (R_right <= 0 && R_right >= numsSize)//数组中没有目标值
		return 0;
	int L_right = Binearch(nums, numsSize, (target - 1));//找到target-1的边界
	return (R_right - L_right);

}