//���һ�������У�������������Ĳ��ܵ���ͬһ����������ô������оͳ�Ϊ �Ȳ����� ��
//��������������������γɵȲ����У��뷵�� true �����򣬷��� false ��

//˼·���ȶ�����������򣬾Ϳ���ֱ�Ӽ������ڵ�������֮��Ĳ�ֵ�Ƿ����
//Ȼ����б��������õȲ����е������жϳ��Ƿ��ǵȲ�����


int Compar(int *a, int *b)
{
	return *a - *b;
}
bool canMakeArithmeticProgression(int* arr, int arrSize){
	qsort(arr, arrSize, sizeof(int), Compar);

	int flag = arr[1] - arr[0];
	for (int i = 1; i<arrSize - 1; i++)
	{
		if (arr[i + 1] - arr[i] != flag)
			return false;
	}
	return true;

}