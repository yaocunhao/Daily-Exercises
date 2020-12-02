#include <stdio.h>
#include <windows.h>
//����һ��ת�������������飬�����Ȳ�֪��������ת���˶���(����, 0 1 2 4 5 6 7���ܱ�Ϊ4 5 6 7 0 1 2).
//������������������Ŀ��ֵ����������������ҵ��������������������򷵻� - 1��
//���������в������ظ��

int FindNum(int arr[], int num,int target)
{
	int left = 0;
	int right = num - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (arr[mid] == target)
			{
				return mid;
			}
			if (arr[mid] >= arr[left])//�������
			{
				if (target < arr[mid]&&target>=arr[left])
					right = mid - 1;
				else
					left = mid +1 ;
			}
			else//�ұ�����
			{
				if (target>arr[mid]&&target<=arr[right])
					left = mid + 1;
				else
					right = mid - 1;
			}
	
		}
		return -1;

}

int main()
{
	int arr[] = {7,6,5,4,3,2,1,0,8};
	int num = sizeof(arr) / sizeof(arr[0]);
	int target =0;
	printf("%d\n",FindNum(arr, num,target));
	system("pause");
	return 0;
}