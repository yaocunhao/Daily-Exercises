class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //两种状态，手持股票，或者不持
        //最多完成两笔交易
        
        int buy1=-prices[0];//第一次买入
        int buy2=-prices[0];//第二次买入
        int sell1=0;//第一次卖出
        int sell2=0;//第二次卖出

        for(int i=1;i<prices.size();i++)
        {
            buy1=fmax(buy1,-prices[i]);//挑选最小的值进行一次买入
            sell1=fmax(sell1,buy1+prices[i]);//挑选一次最大的值，进行第一次卖出
            
            buy2=fmax(buy2,sell1-prices[i]);//买第二次时的利润=第一次的利润-当前股票价格
            sell2=fmax(sell2,buy2+prices[i]);//挑选一个较大的值，进行第二次卖出
        }

        return sell2;
    }
};