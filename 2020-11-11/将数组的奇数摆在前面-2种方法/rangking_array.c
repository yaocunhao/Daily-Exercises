#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)
void Exca(int arr[], int num)
{
	int t = 0;
	int left = 0;
	int right = num - 1;
		while (arr[left] % 2 != 0 && left < right)
		{
			left++;    //һֱ����Ѱ�ң�һֱ�ҵ�ż��λ�ã�
		}
		while ((arr[right] % 2 == 0) && left < right)
		{
			right--;      //һֱ����Ѱ�ң��ҵ�����ֹͣ
		}
		if (left < right)
		{
			t = arr[right];
			arr[right] = arr[left];
			arr[left] = t;
		}
	
}



int main()

{

	int arr[] = { 2, 6, 5, 7, 9, 11, 20, 41, 51, 33, 58 };

	int num = sizeof(arr) / sizeof(arr[0]);

	Exca(arr, num);

	for (int i = 0; i < num; i++)

	{

		printf("%d\n", arr[i]);

	}

	system("pause");

	return;

}