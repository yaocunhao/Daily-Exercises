#include <iostream>
using namespace std;
#include <math.h>

int GetNum(int n)
{
  int count=0;
  for(int i=2;i<=sqrt(n);i++)
  {
    int flag=1;
    while(n%i==0)
    {
      n/=i;
      flag=0;
    }
    if(flag==0)
      count++;
  }
  if(n!=1)
    count++;
  return count;
}

int main()
{
  int num;
  while(cin>>num)
  {
    cout<<GetNum(num)<<endl;
  }
  return 0;
}