int* printNumbers(int n, int* returnSize){
	int max = pow(10, n) - 1;//10��n�η���-1Ϊ��ǰ�������
	int *arr = (int *)malloc(sizeof(int)*max);
	for (int i = 1; i <= max; i++)
	{
		arr[i - 1] = i;
	}
	*returnSize = max;
	return arr;

}

