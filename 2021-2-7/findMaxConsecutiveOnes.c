//����һ�����������飬 ���������������1�ĸ�����

//˼·���������飬��һ�������� ��һ������ֵ�����������������ֵ���ڷ��ر���
//��ֵ�����ر������������0����������㣬

int findMaxConsecutiveOnes(int* nums, int numsSize){
	int max = 0;
	int count = 0;
	for (int i = 0; i<numsSize; i++)
	{
		if (nums[i] == 1)
			count++;
		if (count>max)
			max = count;
		if (nums[i] == 0)
			count = 0;//����
	}
	return max;

}