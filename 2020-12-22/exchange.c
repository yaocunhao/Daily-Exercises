#include <stdio.h>
#include <windows.h>


int* exchange(int* nums, int numsSize){
	//注意判断条件，后面两个if判断不能放在第一个判断的前面；
	//头尾指针法本意是让前面的指针找到偶数，后面的指针找到奇数，停下来后在进行交换，如果
		//将后两个判断放在前面，坐标已近发生了改变，对应的不再是当前下标的元素；

	int start = 0;
	int end = numsSize - 1;
	while (start < end)
	{
		if ((nums[start] % 2 == 0) && (nums[end] % 2 != 0))
		{
			int temp = nums[start];
			nums[start] = nums[end];
			nums[end] = temp;
		}
		if (nums[start] % 2 != 0)
			start++;
		if (nums[end] % 2 == 0)
			end--;
	}
}

int main()
{
	int arr[] = { 1,11,14};
	int size = sizeof(arr) / sizeof(arr[0]);
	exchange(arr,size);
	for (int i = 0; i < size; i++)
	{
		printf("%d\n", arr[i]);
	}
	system("pause");
	return 0;
}