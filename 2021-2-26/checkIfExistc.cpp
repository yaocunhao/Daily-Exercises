
//����һ���������� arr���������Ƿ������������ N �� M������ N �� M ������������N = 2 * M����

bool checkIfExist(int* arr, int arrSize){
	int temp = 0;
	for (int i = 0; i<arrSize; i++)
	{
		if (arr[i] % 2 == 0)//ż������������һ������������
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