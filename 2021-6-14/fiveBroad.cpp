#include <iostream>
using namespace std;
#include <vector>

bool Judge(vector<vector<char>>&board,int x,int y)//每一颗都是最后一颗棋子进行判断
{
    //备份一份
    int _x=x;
    int _y=y;
    
    int up=0;
    int left=0;
    int left_up=0;
  
    char ch=board[x][y];
    //往上判断
    while(x>=0&&board[x][y]==ch)
    {
        up++;
        x--;
        if(up>=5)
          return true;          
    }
    
    //往左判断
    x=_x;
    while(y>=0&&board[x][y]==ch)
    {
        left++;
        y--;
        if(left>=5)
            return true;
    }
    
    //往左上判断
    y=_y;
    while(x>=0&&y>=0&&board[x][y]==ch)
    {
        left_up++;
        x--;
        y--;
        if(left_up>=5)
           return true;
    }
  
        return false;
}

int main()
{
    string str;
    int sub=0;
   vector<vector<char>>arr(20,vector<char>(20,0));
  
    char ch;
  while(cin>>ch)
  {
    arr[0][0]=ch;
    for(int i=0;i<20;i++)
    {
      for(int j=0;j<20;j++)
      {
        if(i==0&&j==0)
          continue;
        cin>>arr[i][j];
      }
    }
   
    int flag=0;
    for(int i=0;i<20;i++)
    {
      for(int j=0;j<20;j++)
      {
        if(arr[i][j]!='.'&&Judge(arr,i,j))
        {
          flag=1;
          break;
        }
      }
      if(flag)
        break;
    }
    if(flag)
      printf("%s\n","Yes");
    else
      printf("%s\n","No");
  }
  
    return 0;
}