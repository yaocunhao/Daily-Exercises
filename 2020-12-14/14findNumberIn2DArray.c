bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
	if (matrixSize == 0 || *matrixColSize == 0)//�л�����Ϊ0
		return false;
	int newrow = 0;
	int newline = *matrixColSize - 1;
	while (newrow >= 0 && newrow<matrixSize&&newline >= 0 && newline<*matrixColSize)
	{
		if (target>matrix[newrow][newline])//��������
			newrow++;
		else if (target<matrix[newrow][newline])//С������
			newline--;
		else//���ڷ���
			return true;
	}
	return false;
}

���ߣ�ych9527
���ӣ�https ://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/solution/c-by-ych9527-y2c0/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������