class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n,0);
        dp[0]=1;
        vector<int> sub(primes.size(),0);//初始时，下标都为0

        for(int i=1;i<n;i++)
        {
            vector<int> record(primes.size(),0);//记录每个 下标*对应的值

            int min=dp[sub[0]]*primes[0];//记录最小值

            for(int j=0;j<primes.size();j++)//记录每个下标*得到的值
            {
                record[j]=dp[sub[j]]*primes[j];
                min=fmin(min,record[j]);//得到最小值
            }
            dp[i]=min;//将最小值填入数组中

            //坐标的更新
            for(int i=0;i<primes.size();i++)//对应的下标自增
            {
                if(record[i]==min)//对应的最小值下标增加
                    sub[i]++;
            }
        }
        return dp[n-1];
    }
};