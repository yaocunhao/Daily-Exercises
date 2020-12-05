//�ⷨ1��
//void rotate(int* nums, int numsSize, int k){
//	for (int i = 0; i<k; i++)
//	{
//		int previous = nums[numsSize - 1];
//		for (int j = 0; j<numsSize; j++)
//		{
//			int temp = nums[j];
//			nums[j] = previous;
//			previous = temp;
//		}
//	}
//
//}
#include <stdio.h>
#include <windows.h>

//�ⷨ2��void Reverse(int arr[], int left, int right)
//{
//	while (left<right)
//	{
//		int temp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = temp;
//		left++;
//		right--;
//	}
//}
//
//void rotate(int* nums, int numsSize, int k){
//	while(k > numsSize)
//	{
//		k -= numsSize;//����ļ�Ϊһ��ѭ���ص�ԭ��
//	}
//	Reverse(nums, 0, numsSize - 1);//������巴ת
//	Reverse(nums, 0, k - 1);//���ǰ�벿�ַ�ת
//	Reverse(nums, k, numsSize - 1);//��ɺ�벿�ַ�ת
//}

//void rotate(int* nums, int numsSize, int k)
//{
//	while (k > numsSize)
//	{
//		k -=numsSize;
//	}
//	int *arr = (int *)malloc(sizeof(int)*numsSize);
//	int count = 0;
//	for (int i=numsSize-k; i < numsSize; i++)
//	{
//		arr[count] = nums[i];//����Ҫ�ߵ����ȿ�����ȥ
//		count++;
//	}
//	for (int j = 0; j< numsSize - k; j++)
//	{
//		arr[count] = nums[j];//�ٽ�����Ŀ�������
//		count++;
//	}
//	for (int j = 0; j < numsSize; j++)
//
//	{
//		nums[j] = arr[j];//������ԭ����
//	}
//}
void rotate(int* nums, int numsSize, int k){
	k %= numsSize;
	int count = 0;
	int previous = nums[0];
	int lable = 0;
	int sub = k;
	while (count < numsSize)
	{
		if (sub < numsSize)
		{
			int temp = nums[sub];
			nums[sub] = previous;
			count++;
			previous = temp;
			sub += k;
		}
		else//�������һ��ϵ�е�ת��
		{
			int temp = nums[sub - numsSize];
			nums[sub - numsSize] = previous;
			count++;
			previous = temp;
			if (sub - numsSize == lable)//�ص�ԭ��
			{
				sub = sub - numsSize + 1;
				lable = sub;
				previous = nums[sub];
				sub += k;
			}
			else
			{
				sub = sub - numsSize + k;
			}
			
		}
	}
}

int main()
{
	int nums[] = { 1,2,3};
	int k = 2;
	int numsSize=sizeof(nums)/sizeof(nums[0]);
	rotate(nums, numsSize, k);
	for (int i = 0; i < numsSize; i++)
	{
		printf("%d\n", nums[i]);
	}
	system("pause");
	return 0;
}