//������ռ�ȳ���һ���Ԫ�س�֮Ϊ��ҪԪ�ء�����һ���������飬�ҵ�������ҪԪ�ء���û�У����� - 1��

int majorityElement(int* nums, int numsSize) {
	int index = 0, number = nums[0], i;
	for (i = 0; i<numsSize; i++)
	{
		if (nums[i] == number)index++;
		else index--;
		if (index == 0)number = nums[i + 1];
	}
	index = 0;
	for (i = 0; i<numsSize; i++)
	{
		if (nums[i] == number)index++;
	}
	return index>numsSize / 2 ? number : -1;
}
