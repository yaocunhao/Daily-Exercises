#include <iostream>
using namespace std;
#include <vector>


int main()
{
    int n;
    while(cin>>n)
    {
         int val=-1;
        int count=1;
        vector<int> arr(1,1);
        while(count<n)
        {
            arr.resize(arr.size()+2,0);
            arr[arr.size()-1]=1;//最后一个是1
            arr[0]=1;
            for(int i=1;i<arr.size()-1;i++)//，第一个是1，
            {
                if(i-2>=0)//dp[i]=dp[i-1]+dp[i-2]+dp[i-3]
                    arr[i]=arr[i]+arr[i-1]+arr[i-2];
                else
                    arr[i]=arr[i]+arr[i-1];
                
                if(count+1==n&&arr[i]%2==0)
                {
                    val=i+1;
                    break;
                }
            }
            count++;
        }
        cout<<val<<endl;
    }
    
    
    
    
    return 0;
}