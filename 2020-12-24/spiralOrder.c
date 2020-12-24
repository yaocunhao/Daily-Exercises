//确定好上下左右四个边界，然后进行循环复制到一维数组之中，注意边界问题
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
	if (matrix == NULL || matrixSize == 0 || matrixColSize == NULL)
	{
		*returnSize = 0;
		return NULL;
	}
	int left = 0, right = *matrixColSize - 1, up = 0, down = matrixSize - 1;
	int size = matrixSize*(*matrixColSize);
	int count = 0;
	int *arr = (int *)malloc(sizeof(int)*size);
	while (count<size)
	{
		for (int i = left; i <= right; i++)
		{
			arr[count] = matrix[up][i];
			count++;
		}
		up++;
		if (count == size)
			break;

		for (int i = up; i <= down; i++)
		{
			arr[count] = matrix[i][right];
			count++;
		}
		right--;
		if (count == size)
			break;

		for (int i = right; i >= left; i--)
		{
			arr[count] = matrix[down][i];
			count++;
		}
		down--;
		if (count == size)
			break;

		for (int i = down; i >= up; i--)
		{
			arr[count] = matrix[i][left];
			count++;
		}
		left++;
		if (count == size)
			break;

	}
	*returnSize = size;
	return arr;

}
