#include <iostream>
using namespace std;
#include <string>
#include <vector>

bool Judge(string &str, int sub)
{
	if ((str[sub] >= '0'&&str[sub] <= '9') || (str[sub] >= 'a'&&str[sub] <= 'z') || (str[sub] >= 'A'&&str[sub] <= 'Z'))//*和.可以匹配的字符
		return true;
	return false;
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
		dp[0][0] = true;//两个都是空字符串

		for (int i = 0; i < s1.size(); i++)
		{
			if (s1[i] == '*')
				dp[i + 1][0] = true;
			else
				break;
		}

		for (int i = 0; i<s1.size(); i++)
		{
			for (int j = 0; j<s2.size(); j++)
			{
				if (s1[i] == '?')
				{
					if (Judge(s2, j))
						dp[i + 1][j + 1] = dp[i][j];
				}
				else if (s1[i] == '*')
				{
					if (dp[i][j + 1] == true)//匹配0个
						dp[i + 1][j + 1] = true;
					else if (Judge(s2, j))//匹配多个
						dp[i + 1][j + 1] = dp[i + 1][j];
				}
				else//普通字符
				{
					if (s1[i] == s2[j] || s1[i] - 32 == s2[j] || s1[i] + 32 == s2[j])
						dp[i + 1][j + 1] = dp[i][j];
				}
			}
		}
		if (dp[s1.size()][s2.size()])
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}


	return 0;
}