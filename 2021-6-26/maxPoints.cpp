class Solution {
public:

	int maxchild(int y, int x)//求最大公约数
	{
		if (x == 0)//分子为0
			return 1;
		int c = y%x;
		while (c)
		{
			y = x;
			x = c;
			c = y%x;
		}
		return x;
	}
	int maxPoints(vector<vector<int>>& points) {
		int max = 0;
		for (int i = 0; i<points.size(); i++)
		{
			unordered_map<string, int> mp;//用string来保存斜率
			int x1 = points[i][0];
			int y1 = points[i][1];
			for (int j = i + 1; j<points.size(); j++)
			{
				int x2 = points[j][0];
				int y2 = points[j][1];

				int y = y2 - y1;
				int x = x2 - x1;
				int flag = 1;
				if (x*y<0)//算符号
					flag = -1;

				y = abs(y);
				x = abs(x);
				int num = maxchild(y, x);//得到最大公约数
				//约分处理
				y /= num;
				x /= num;

				//得到斜率
				string k;
				if (flag == -1)
					k += '-';

				k += to_string(y);
				k += to_string(x);

				if (x == 0)//此时为竖线
					mp[to_string(abs(x2))]++;
				else
					mp[k]++;//该斜率上增加一个点
			}
			for (auto&e : mp)
			{
				max = fmax(e.second, max);
			}
		}
		return max+1;
	}
};