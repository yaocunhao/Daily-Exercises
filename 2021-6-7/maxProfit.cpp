class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //dp[i][n]表示在第i天结束时的状态
        //其中 n有三种状态 
        //dp[i][0]=持有股票  dp[i][1]=处于冷冻期  dp[i][2]=不处于冷冻期，且不持有股票

        //第n天的状态只于第n-1天有关系
        
        //dp[i][0]=max(dp[i-1][0],dp[i-1][2] - prices[i])//前一天就有股票，或者今天买的

        //dp[i][1] =prices[i] + dp[i-1][0] //在当天卖出了股票,昨天就是有股票的 + 当天的股票价格

        //dp[i][2] = max(dp[i-1][1],dp[i-2][2])//当天没有进行任何操作,前一天没有股票或者前一天处于冷冻期

        if(prices.empty())
            return 0;

       vector<vector<int>>dp(prices.size(),vector<int>(3,0));
        dp[0][0]=-prices[0];//第一天买入股票，收入为负数


        for(int i=1;i<prices.size();i++)
        {
            dp[i][0]=fmax(dp[i-1][0],dp[i-1][2] - prices[i]);
            dp[i][1] =prices[i] + dp[i-1][0];
            dp[i][2] = fmax(dp[i-1][1],dp[i-1][2]);
        }

        return fmax(dp[prices.size()-1][0],fmax(dp[prices.size()-1][1],dp[prices.size()-1][2]));
    }
};