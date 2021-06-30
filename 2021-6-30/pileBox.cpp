class Solution {
public:
    struct Less
    {
        bool operator()(vector<int> x,vector<int> y) 
        {
            return x[0]<y[0];
        }
    };
    int pileBox(vector<vector<int>>& box) {
        //具有三个维度的递增的子序列
        //选择一个维度进行排序 -> 两个维度递增的子序列
        
        sort(box.begin(),box.end(),Less());
        vector<int>dp;
        int max=0;
        
        for(int i=0;i<box.size();i++)
        {
            dp.push_back(box[i][2]);
            for(int j=i-1;j>=0;j--)
            {
                if((box[i][2]>box[j][2])&&(box[i][1]>box[j][1])&&(box[i][0]>box[j][0]))//两者都大于前面
                    dp[i]=fmax(dp[i],box[i][2]+dp[j]);
            }
            max=fmax(max,dp[i]);
        }

        return max;
    }
};