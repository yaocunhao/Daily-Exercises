��������������Ҳ��ظ����֣���ô�������ǵ�һ��ȡ�м��mid���������û��ȱʧԪ��
nums[mid]һ������mid������ȱʧ��Ԫ�غ�Ͳ�һ������ˣ�
�����ȣ�˵��ǰ�벿�����������ʱ�����ǽ�������С��left = mid + 1��
��������˵��ȱʧ�����ִ���ǰ�벿�֣���ʱright = mid - 1;
ֱ��ѭ��ֹͣ����ʱleft��ֵ���Ƕ�Ӧ��ȱʧ������
int missingNumber(int* nums, int numsSize){
	int left = 0;
	int right = numsSize - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (nums[mid] == mid)//���������
			left = mid + 1;
		else//����������
			right = mid - 1;
	}
	return left;

}