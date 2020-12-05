#include <stdio.h>
#include <windows.h>
//对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果 X = 1231，那么其数组形式为 [1,2,3,1]。
//给定非负整数 X 的数组形式 A，返回整数 X + K 的数组形式。
//示例 1：
//输入：A = [1, 2, 0, 0], K = 34
//输出：[1, 2, 3, 4]
//解释：1200 + 34 = 1234
//此处撰写解题思路
//1.首先判断K的位数num，通过与Asize的比较得到新开辟的数组的长度，因为新的数组最长就是向前进1，
//即较大数组的长度 + 1;
//2.比较原数组的长度和K取余之后的位数num，然后用较长的作为条件判断
//3.将k取余与Asize倒叙相加得到sum再取余赋值给新的数组，再判断sum是否大于10，即是否需要向前进1；
//条件结束之后，判断是否需要进1，需要进1则returnsize为新的数组的长度即newsize，否则为newsize - 1；
//4.完成新数组的赋值之后，将得到的数组进行颠倒则得到了满足要求的数组；

int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
	int i = 0;
	int num = 0;
	int k2 = K;
	int newsize = 0;
	while (k2)
	{
		k2 /= 10;
		num++;//判断k的位数
	}
	if (num>ASize)
		newsize = num + 1;//两个相加也不会越界
	else
		newsize = ASize + 1;
	int *Karr = (int *)malloc(sizeof(int)*newsize);//开辟数数组
	int sum = 0;
	i = 0;//i重置
	if (ASize >= num)
	{
		while (ASize)
		{
			sum = (A[ASize - 1] + K % 10 + sum);//A数组倒过来+K的余数
			Karr[i] = (sum % 10);//将结果放到新数组
			sum /= 10;
			K /= 10;
			ASize--;
			i++;
		}
		if (sum != 0)
		{
			Karr[i] = sum;
			*returnSize=newsize;
			i++;
		}
		else
			*returnSize=newsize - 1;
	}
	else
	{
		while (ASize)
		{
			sum = A[ASize - 1] + K % 10 + sum;
			Karr[i] = sum % 10;
			sum /= 10;
			K /= 10;
			ASize--;
			i++;
		}
		while (K)//k比数组位数多
		{
			sum = K % 10 + sum;
			Karr[i] = sum % 10;
			K /= 10;
			sum /= 10;
			i++;
		}
		if (sum != 0)//向前进位
		{
			Karr[i] = sum;
			*returnSize=newsize;
			i++;
		}
		else
			*returnSize=newsize - 1;
	}

	int left = 0;
	int right = *returnSize-1;
	while (left < right)
	{
		int t = Karr[left];
		Karr[left] = Karr[right];
		Karr[right] = t;
		left++;
		right--;
	}
	return Karr;
}

int main()
{
	int A[] = { 1, 2, 0, 0 };
	int ASize = sizeof(A) / sizeof(A[0]);
	int K= 10;
	int returnSize = 0;
	int *p=addToArrayForm(A,ASize,K, &returnSize);
	int *arr = (int *)malloc(sizeof(int)*(returnSize));
	arr = p;
	for (int i = 0; i <returnSize; i++)
	{
		printf("%d\n", arr[i]);
	}
	system("pause");
	return 0;
}