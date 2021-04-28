#include <iostream>
using namespace std;
#include <vector>


int main()
{

    int n,m;
   while(cin>>n>>m)
   {
       vector<vector<int>> ret;
        vector<int> temp(m+1,0);
        for(int i=0;i<=n;i++)
        {
            ret.push_back(temp);
        }

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0&&j==0)
                    ret[i][j]=1;
                else if(i==0&&j!=0)//第一行、往右走
                    ret[i][j]=ret[i][j-1];
                else if(i!=0&&j==0)//第一列往下走
                    ret[i][j]=ret[i-1][j];
                else
                    ret[i][j]=ret[i-1][j]+ret[i][j-1]; //上+左      
            }
        }
        cout<<ret[n][m]<<endl;
   }
    
    return 0;
}