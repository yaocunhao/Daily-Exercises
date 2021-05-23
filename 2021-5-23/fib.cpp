#include <iostream>
using namespace std;
#include <vector>

//n = 1 2 3 4 5 6 7 8 9 
//对应的矩阵值为 1 2 3 5 8 13 斐波那契数列

int main()
{
    vector<int> fib(10001,0);//记录斐波那契数
    fib[1]=1;
    fib[0]=1;
    for(int i=2;i<=10000;i++)
    {
        fib[i]=(fib[i-1]+fib[i-2])%10000;
    }
    
    int num=0;
    while(cin>>num)//有多少个数
    {
        int count=0;
        for(int i=0;i<num;i++)//该组内的数据
        {
            cin>>count;
            printf("%04d",fib[count]);//输出四个字符，不够用0补
        }
        cout<<endl;//当前组的数据输入完毕，换行
    }
    return 0;
}