#include <iostream>
#include <vector>
using namespace std;
#include <math.h>

void GetNum(int x, vector<int> &arr)//求下一步的所有值
{
	arr.clear();//先清空
	for (int i = 2; i <= sqrt(x); i++)//从后往前除，第一个位置就是最大值
	{
		if (x%i == 0)
		{
			arr.push_back(i);

			if (x / i != i)
				arr.push_back(x / i);
		}
	}
}

int main()
{
	int n;//出发点
	int m;
	while (cin >> n)
	{
		cin >> m;//跳到m位置

		vector<int> count(m + 1, 0);//count[i]表示跳到i位置所需要的步伐数

		vector<int> arr;
		GetNum(n, arr);//获取下一步能到达的位置

		for (auto&e : arr)
		{
			if (n + e <= m)//没有超出范围
				count[n + e] = 1;//表示跳到当前位置，所需要的步数为1
		}

		for (int i = n + 1; i <= m; i++)
		{
			if (count[i] == 0)//不能从当前位置出发
				continue;

			GetNum(i, arr);//获取下一步能到达的位置

			for (auto&e : arr)
			{
				if (e + i <= m)//没有超出范围
				{
					if (count[i + e] == 0)//第一次到达
						count[i + e] = count[i] + 1;
					else//选最小值
						count[i + e] = fmin(count[i + e], count[i] + 1);
				}
			}
		}

		if (n == m)
			cout << 0 << endl;
		else if (count[m] == 0)
			cout << -1 << endl;
		else
			cout << count[m] << endl;
	}

	return 0;
}