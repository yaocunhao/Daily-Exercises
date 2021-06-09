//回溯算法

#include <iostream>
using namespace std;
#include <vector>
#include <math.h>

void  GetBlack(vector<vector<char>>&arr,int i,int j,int &count)
{
    int row=arr.size()-1;
    int col=arr[0].size()-1;
    if(i<0||i>row||j<0||j>col||(arr[i][j]!='@'&&arr[i][j]!='.'))
        return ;
    
    count++;
    arr[i][j]='0';//先破坏
    //往上下左右出发
    GetBlack(arr, i+1, j, count);
    GetBlack(arr, i-1, j, count);
    GetBlack(arr, i, j+1, count);
    GetBlack(arr, i, j-1, count);
    
}

int main()
{
    int m,n;//m行n列
    while(cin>>m)
    {
        cin>>n;
        vector<vector<char>> arr(m,vector<char>(n,'0'));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                char ch;
                cin>>ch;
                arr[i][j]=ch;
            }
        }
        //寻找起点
        int max=0;
         for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i][j]=='@')
                {
                    int count=0;
                    GetBlack(arr,i,j,count);
                    max=count;
                    break;
                }
            }
        }
        cout<<max<<endl;
        
        
    }
    
    return 0;
}