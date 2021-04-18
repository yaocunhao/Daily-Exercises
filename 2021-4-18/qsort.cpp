#include <iostream>
using namespace std;
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <windows.h>




int Getmid(vector<int>&arr,int begin, int end)
{
	int mid = (end-begin)/2;

	if (arr[begin] >= arr[end])
	{
		if (arr[begin] >= arr[mid])
		{
			if (arr[mid] >= arr[end])
				return mid;
			else
				return end;
		}
		else
		{
			return begin;
		}
	}
	else//begin<end
	{
		if (arr[mid] <= arr[begin])
			return begin;
		else
		{
			if (arr[mid] >= arr[end])
				return end;
			else
				return begin;
		}
	}
}

//int partion(vector<int> &arr, int begin, int end)
//{
//	int mid = Getmid(arr, begin, end);
//	swap(arr[begin], arr[mid]);
//	int key = begin;
//
//	while (begin < end)
//	{
//		while (begin<end&&arr[end] <= arr[key])
//			end--;
//		while (begin<end&&arr[begin] >= arr[key])
//			begin++;
//		//if (begin < end)
//			swap(arr[begin], arr[end]);
//	}
//	swap(arr[key], arr[begin]);
//	return begin;
//}

int partion2 (vector<int> &arr, int begin, int end)
{
	int mid = Getmid(arr, begin, end);
	swap(arr[mid], arr[end]);
	int key = arr[begin];

	while (begin < end)
	{

		while (begin<end&&arr[end] <= key)
		{
			end--;
		}

		arr[begin] = arr[end];
		while (begin < end&&arr[begin] >= key)
		{
			begin++;
		}

		arr[end] = arr[begin];
	}
	arr[begin] = key;
	return begin;
}

int partion(vector<int> &arr, int begin, int end)
{
	int mid = Getmid(arr, begin, end);
	swap(arr[mid], arr[end]);
	int prev = begin;
	int cur = prev + 1;
	while (cur <= end)
	{
		if (arr[cur] >= arr[begin] && ++prev != arr[cur])
			swap(arr[cur], arr[prev]);
		cur++;
	}
	swap(arr[begin], arr[prev]);
	return prev;
}

void QuickSort(vector<int> &arr, int begin, int end)
{
	if (begin >= end)
		return ;

	int mid = partion(arr, begin, end);
	QuickSort(arr, begin, mid - 1);
	QuickSort(arr, mid + 1, end);
}

void test1(vector<int> arr)
{
	QuickSort(arr, 0, arr.size()-1);
	
	auto it = arr.begin();
	while (it != arr.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

void QuickSort2(vector<int> &arr, int begin, int end)
{
	if (begin >= end)
		return;

	int mid = partion2(arr, begin, end);
	QuickSort(arr, begin, mid - 1);
	QuickSort(arr, mid + 1, end);
}

void test2(vector<int> arr)
{
	QuickSort2(arr, 0, arr.size() - 1);

	auto it = arr.begin();
	while (it != arr.end())
	{
		cout << *it << " ";
		it++;
	}
}

int main()
{
	vector<int> arr;
	arr.resize(20, 0);

	srand((unsigned)time(NULL));

	for (int i = 0; i < arr.size(); i++)
	{
		arr[i] = rand() % 1000;
	}

	test1(arr);
	test2(arr);

	
	system("pause");
	return 0;
}

