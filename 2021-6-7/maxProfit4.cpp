class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()==0||k==0)
            return 0;
        vector<int> buy(k,-prices[0]);
        vector<int> sell(k,0);

        for(int i=1;i<prices.size();i++)
        {
            for(int j=0;j<k;j++)
            {
                if(j==0)//第一次
                {
                    buy[j]=fmax(buy[j],-prices[i]);
                    sell[j]=fmax(sell[j],buy[j]+prices[i]);
                }
                else//非第一次
                {
                    buy[j]=fmax(buy[j],sell[j-1]-prices[i]);//上一次卖出去的利润 - 当前买股价格
                    sell[j]=fmax(sell[j],buy[j]+prices[i]);//判断是否卖出去
                }
            }
        }

        return sell[k-1];
    }
};