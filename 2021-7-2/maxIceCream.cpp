class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int sub=0;
        while(coins>=0&&sub<costs.size())
        {
            if(coins>=costs[sub])
            {
                coins-=costs[sub++];
            }
            else
                break;
        }

        return sub;

    }
};