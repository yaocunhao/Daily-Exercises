#include <iostream>
using namespace std;
#include <windows.h>

class Sum
{
public:
	Sum()
	{
		_ret += _i;
		_i++;
	}

	Sum(const Sum &ret)
	{
		_ret = ret;
	}

	static int GetRet()
	{
		return _ret;
	}

private:
	static int _i;
	static int _ret;
};
int Sum::_i = 1;
int Sum::_ret = 0;

class Solution {
public:
	int Sum_Solution()
	{
		Sum arr[5];
		return Sum::GetRet();
	}

};


int main()
{
	Solution a;
	int ret=a.Sum_Solution();
	cout << ret << endl;


	system("pause");
	return 0;



}