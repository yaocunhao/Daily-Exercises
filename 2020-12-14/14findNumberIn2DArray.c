bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
	if (matrixSize == 0 || *matrixColSize == 0)//行或者列为0
		return false;
	int newrow = 0;
	int newline = *matrixColSize - 1;
	while (newrow >= 0 && newrow<matrixSize&&newline >= 0 && newline<*matrixColSize)
	{
		if (target>matrix[newrow][newline])//大于往下
			newrow++;
		else if (target<matrix[newrow][newline])//小于往左
			newline--;
		else//等于返回
			return true;
	}
	return false;
}

作者：ych9527
链接：https ://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/solution/c-by-ych9527-y2c0/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。