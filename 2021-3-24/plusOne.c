力扣66.加1

int* (int* digits, int digitsSize, int* returnSize){

	//最后一位+1分为三种情况
	//没有进位直接+1
	//到不了最高位，也是直接加
	//可以进位到最高位，直接开辟比原数组的多一个空间，最高位为1，其余为零即可

	if (digits[digitsSize - 1] != 9)//最低位不为9
	{
		digits[digitsSize - 1] += 1;
		*returnSize = digitsSize;
		return digits;
	}
	//最低位为9
	int count = -1;

	for (int i = digitsSize - 1; i >= 0; i--)
	{
		if (digits[i] != 9)
		{
			count = i;//找到不为9的哪一位
			break;
		}
	}
	if (count == -1)//都为9
	{
		*returnSize = digitsSize + 1;
		int *ret = (int *)calloc(digitsSize + 1, sizeof(int));
		ret[0] = 1;
		return ret;
	}
	//count位置不为9

	digits[count] += 1;
	for (int i = count + 1; i<digitsSize; i++)
	{
		digits[i] = 0;
	}
	*returnSize = digitsSize;
	return digits;

}