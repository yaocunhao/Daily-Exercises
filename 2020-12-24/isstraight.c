int com(int *a, int *b)
{
	return *a - *b;
}

bool isStraight(int* nums, int numsSize){
	//�����ٱ�������û���ظ�ֵ�������ֱ�ӷ��أ�
	//ͳ�����й��������������ֵ����Сֵ<5
	qsort(nums, numsSize, sizeof(int), com);
	int count = 0;//ͳ�ƹ����ĸ���
	for (int i = 0; i<numsSize - 1; i++)
	{
		if (nums[i] == 0)
			count++;
		if (nums[i] == nums[i + 1] && nums[i] != 0)
			return false;
	}
	//�������ź�����û���ظ�ֵ
	if (nums[4] - nums[count]<5)
		return true;
	else
		return false;

}
