//����һ���ǿ����飬���ش������� ��������� ����������ڣ��򷵻���������������
//ע�⣬Ҫ�󷵻ص������������ָ��������Ψһ���ֵ�����
//��������ֵΪ2���������Ƕ��ŵڶ���

//�ⷨ��
//1.����ĸ��Ӷ�ΪNlongN��������һ�������ʱ�临�Ӷ�ΪN�����ѡ�������
//2.ע��߽�����⣬��˱����Ķ�����long
//3.����һ������count�������������е��ظ�����

int thirdMax(int* nums, int numsSize){
	long lable1 = 0;
	long lable2 = 0;
	long lable3 = 0;
	long count = 0;

	for (int i = 0; i<numsSize; i++)
	{
		if ((nums[i] == lable1 || nums[i] == lable2 || nums[i] == lable3) && nums[i] != 0)
			continue;

		if (nums[i]>lable1)//���ֵ
		{
			if (lable2 != 0)//lable3����Ϊ����
			{
				lable3 = lable2;
			}
			lable2 = lable1;
			lable1 = nums[i];
			count++;
		}
		else if (nums[i]>lable2)//�ڶ���
		{
			lable3 = lable2;
			lable2 = nums[i];
			count++;
		}
		else if (nums[i]>lable3 || lable3 == 0)
		{
			lable3 = nums[i];
			count++;
		}
	}

	if (numsSize<3 || count<3)
		return lable1;

	return lable3;

}