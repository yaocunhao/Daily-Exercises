/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int comp(int *x, int *y)
{
	return (*x - *y);
}
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
	int *dst = (int *)malloc(sizeof(int)*k);
	qsort(arr, arrSize, sizeof(int), comp);
	for (int i = 0; i<k; i++)
	{
		*(dst + i) = arr[i];
	}
	*returnSize = k;
	return dst;

}