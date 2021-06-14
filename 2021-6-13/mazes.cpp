//回溯法
#include <iostream>
using namespace std;
#include <vector>
#include <math.h>

void GetNum(vector<vector<char>>&arr,int x,int y,int num,int &min)
{
    if(x<0||x>9||y<0||y>9||arr[x][y]=='#')
        return;
    
        num++;
    
    if(min!=0&&num>=min)
        return;
        
    if(x==9&&y==8)
    {
        if(min==0)
            min=num-1;
        else
            min=fmin(num,min)-1;
        return;
    }
    
    arr[x][y]='#';
    //往四个方向走
    GetNum(arr,  x-1,  y,  num,  min);
    GetNum(arr,  x+1,  y,  num,  min);
    GetNum(arr,  x,  y+1,  num,  min);
    GetNum(arr,  x,  y-1,  num,  min);
    
    arr[x][y]='.';//回溯
}

int main()
{
    char ch;
    while(cin>>ch)
    {
        vector<vector<char>> arr(10,vector<char>(10,0));
        arr[0][0]=ch;
        int a=0;
        int b=0;
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(i==0&&j==0)
                    j=1;
                cin>>arr[i][j];
            }
        }
        int min=0;
        GetNum(arr, 0, 1, 0, min);
        cout<<min<<endl;
    }
    return 0;
}