class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        //每进行一次买入卖出，需要交一笔手续费
        //dp[i][n]表示当天结束时的状态
        //此时有两种状态
        //dp[i][0] 表示手里有股票
        //dp[i][1] 表示手里没有股票

        vector<vector<int>>dp(prices.size(),vector<int>(2,0));
        if(prices.size()==0)
            return 0;

        dp[0][0]=-prices[0];//第一天买入股票

        for(int i=1;i<prices.size();i++)//从第二天开始
        {
            dp[i][0]=fmax(dp[i-1][0],dp[i-1][1]-prices[i]);//上一天，或者今天买入的
            dp[i][1]=fmax(dp[i-1][1],dp[i-1][0]+prices[i]-fee);//今天卖出去了，或者本来就没有
        }

        return fmax(dp[prices.size()-1][0],dp[prices.size()-1][1]);
    }
};