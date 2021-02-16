//如果一个数列中，任意相邻两项的差总等于同一个常数，那么这个数列就称为 等差数列 。
//如果可以重新排列数组形成等差数列，请返回 true ；否则，返回 false 。

//思路：先对数组进行排序，然后对齐进行遍历，利用等差数列的性质比较相邻的两个数之间的差值是否相等



int Compar(int *a, int *b)
{
	return *a - *b;
}
bool canMakeArithmeticProgression(int* arr, int arrSize){
	qsort(arr, arrSize, sizeof(int), Compar);

	int flag = arr[1] - arr[0];
	for (int i = 1; i<arrSize - 1; i++)
	{
		if (arr[i + 1] - arr[i] != flag)
			return false;
	}
	return true;

}