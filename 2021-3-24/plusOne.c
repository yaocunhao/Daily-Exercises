����66.��1

int* (int* digits, int digitsSize, int* returnSize){

	//���һλ+1��Ϊ�������
	//û�н�λֱ��+1
	//���������λ��Ҳ��ֱ�Ӽ�
	//���Խ�λ�����λ��ֱ�ӿ��ٱ�ԭ����Ķ�һ���ռ䣬���λΪ1������Ϊ�㼴��

	if (digits[digitsSize - 1] != 9)//���λ��Ϊ9
	{
		digits[digitsSize - 1] += 1;
		*returnSize = digitsSize;
		return digits;
	}
	//���λΪ9
	int count = -1;

	for (int i = digitsSize - 1; i >= 0; i--)
	{
		if (digits[i] != 9)
		{
			count = i;//�ҵ���Ϊ9����һλ
			break;
		}
	}
	if (count == -1)//��Ϊ9
	{
		*returnSize = digitsSize + 1;
		int *ret = (int *)calloc(digitsSize + 1, sizeof(int));
		ret[0] = 1;
		return ret;
	}
	//countλ�ò�Ϊ9

	digits[count] += 1;
	for (int i = count + 1; i<digitsSize; i++)
	{
		digits[i] = 0;
	}
	*returnSize = digitsSize;
	return digits;

}