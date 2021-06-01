#include <iostream>
using namespace  std;
#include <vector>

void Init(vector<int> &arr)
{
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i<arr.size(); i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000;
	}
}

int main()
{
	int n;
	vector<int> arr(100001, 0);
	Init(arr);

	while (cin >> n)
	{
        if(n<29)
            printf("%d\n",arr[n]);
        else
            printf("%06d\n",arr[n]);
	}

	return 0;
}