//������ռ�ȳ���һ���Ԫ�س�֮Ϊ��ҪԪ�ء�����һ���������飬�ҵ�������ҪԪ�ء���û�У����� - 1��

//˼·������Ħ��ͶƱ����Ѱ�ҵ������е���������ͳ�Ƹ��������ֵĴ�����Ȼ����бȽϣ��������Ƿ�
//�����������һ��

int majorityElement(int* nums, int numsSize) {
	int index = 0, number = nums[0], i;
	//������һ�飬�ҵ�����
	for (i = 0; i<numsSize; i++)
	{
		if (nums[i] == number)
			index++;
		else
			index--;
		if (index == 0)//����ȷ������
			number = nums[i + 1];
	}
	//�����жϣ����������Ƿ񳬹����������һ��
	index = 0;
	for (i = 0; i<numsSize; i++)
	{
		if (nums[i] == number)
			index++;
	}
	return index>numsSize / 2 ? number : -1;
}
