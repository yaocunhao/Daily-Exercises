//�����г��ִ�������һ�������
//����1����������λ��
//
//int com(int *x, int *y)
//{
//	return (*x - *y);
//}
//int majorityElement(int* nums, int numsSize){
//
//	qsort(nums, numsSize, sizeof(int), com);
//	return nums[numsSize / 2];
//
//}

//��Ħ��ͶƱ��	
int majorityElement(int* nums, int numsSize){
	int value = 0;
	int count = 0;
	for (int i = 0; i<numsSize; i++)
	{
		if (count == 0)
			value = nums[i];//ÿ��ȡ1��Ԫ��
		if (value == nums[i])
			count++;
		else
			count--;
	}
	return value;
}

