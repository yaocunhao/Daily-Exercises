
class Solution {
public:
	/**
	*	正数数组中的最小不可组成和
	*	输入：正数数组arr
	*	返回：正数数组中的最小不可组成和
	*/
	int getFirstUnFormedNum(vector<int> arr, int len) {
		if (len == 1)
			return arr[0] + 1;

		//算出最小、最大值
		int min = arr[0];
		int max = 0;
		for (auto&e : arr)
		{
			min = fmin(min, e);
			max += e;
		}
		//cout << min << " " << max << endl;
		//判断从[min+1,max-1]中是否有arr中元素不能够成的元素  -> 01背包问题
		vector<vector<bool>>dp(len + 1, vector<bool>(max + 1, false));
		//dp[i][j]表示从arr中选取i个元素，看是否能够构成j
		dp[0][0] = true;//0个元素可以构成0

		for (int i = 0; i<len; i++)
		{
			for (int j = min; j<max; j++)
			{
				if (j == arr[i])//表示一个元素直接构成
					dp[i + 1][j] = true;
				else if (j - arr[i] >= 0)//表示可拿可不拿
					dp[i + 1][j] = dp[i][j] || dp[i][j - arr[i]];//dp[i][j]表示没有拿，dp[i][j-a[i]]表示拿了
				else//不可以拿
					dp[i + 1][j] = dp[i][j];
			}
		}

		/*for (int j = min + 1; j < max; j++)
		{
			cout << j << " ";
		}
		cout << endl;
		for (int i = 0; i < len; i++)
		{
			for (int j = min + 1; j < max; j++)
			{
				cout << dp[i + 1][j] << " ";
			}
			cout << endl;
				
		}*/

		for (int i = min + 1; i<max; i++)
		{
			if (dp[len][i] == false)
				return i;
		}


		return max + 1;
	}
};