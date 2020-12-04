#include <stdio.h>
#include <windows.h>
#include <math.h>
//将数组元素与K相加，再分散到数组
int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
	int ret = 0;
	int val = 0;
	int count = 0;
	for (int i = 0; i<ASize; i++)
	{
		ret += A[i];
	}
	ret = ret + K;
	val = ret;
	while (ret)
	{
		ret /= 10;
		count++;
	}
	for (int i = count - 1; i >= 0; i--)
	{
		returnSize[i] = (val % 10);
		val /= 10;
	}
	return returnSize;
}
int main()
{
	int A[] = { 1, 2, 0, 0 };
	int ASize = 4;
	int K = 34;
	int returnSize[2];
	addToArrayForm(A, ASize, K, returnSize);
	printf("%d\n%d\n", returnSize[0], returnSize[1]);
	printf("%lf\n", pow(2,10));
	system("pause");
		return 0;
}