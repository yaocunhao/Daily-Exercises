
//给你一个整数数组 arr，请你检查是否存在两个整数 N 和 M，满足 N 是 M 的两倍（即，N = 2 * M）。

bool checkIfExist(int* arr, int arrSize){
	int temp = 0;
	for (int i = 0; i<arrSize; i++)
	{
		if (arr[i] % 2 == 0)//偶数才能是另外一个数的整数倍
		{
			temp = arr[i];
		}
		for (int j = 0; j<arrSize; j++)
		{
			if (2 * arr[j] == temp&&i != j)
				return true;
		}
	}
	return false;

}