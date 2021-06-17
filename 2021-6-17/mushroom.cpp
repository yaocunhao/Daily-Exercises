#include <iostream>
using namespace std;
#include <vector>
#include <math.h>

int main()
{
	int n, m, k;
	int x, y;
	while (cin >> n)//[n,m]
	{
		cin >> m;
		cin >> k;
		vector<vector<double>> arr(n, vector<double>(m, 1));

		for (int i = 0; i<k; i++)
		{
			cin >> x >> y;
			arr[x - 1][y - 1] = 0;//表示每行的蘑菇
		}
      
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<m; j++)
			{
              if(i==0&&j==0)
                continue;
              if(arr[i][j]==0)//有蘑菇的路径概率为0，不用走了
                  continue;
			  else if(i==0)
              {
                if(n>1)//不是只有一行
                  arr[i][j]=arr[i][j-1]*0.5;
                else
                  arr[i][j]=arr[i][j-1];
              }
              else if(j==0)
              {
                if(m>1)//不是只有一列
                  arr[i][j]=arr[i-1][j]*0.5;
                else
                  arr[i][j]=arr[i-1][j];
              }
              else if(i==n-1&&j!=m-1)//在最后一行
                 arr[i][j]=arr[i-1][j]*0.5+arr[i][j-1];
              else if(i!=n-1&&j==m-1)//在最后一列
                arr[i][j]=arr[i-1][j]+arr[i][j-1]*0.5;
              else if(i!=n-1&&j!=m-1)//在中间
                arr[i][j]=arr[i-1][j]*0.5+arr[i][j-1]*0.5;
              else//在最后那个位置
                arr[i][j]=arr[i-1][j]+arr[i][j-1];
			}
		}
		printf("%.2f\n", arr[n - 1][m - 1]);
	}
	return 0;
}

