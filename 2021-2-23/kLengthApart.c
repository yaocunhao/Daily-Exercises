//����һ�������� 0 �� 1 ��ɵ����� nums �Լ����� k��������� 1 ��������� k ��Ԫ�أ�
//�򷵻� True �����򣬷��� False ��

//˼·���������飬���ҵ���һ��1��Ȼ��������������㣬��ͳ������1֮������0�ĸ���

bool kLengthApart(int* nums, int numsSize, int k){
	int lable = -1;
	for (int i = 0; i<numsSize; i++)
	{
		if (nums[i] == 1)//����
		{
			if (lable<k&&lable != -1)//�Ѿ���ʼͳ��
				return false;
			lable = 0;
		}
		else
		{
			if (lable != -1)//����Ƿ�������һ��1
				lable++;
		}
	}
	return true;
}