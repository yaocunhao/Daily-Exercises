class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k)
     {
        //dp[i][j]表示第i轮，传递给编号j的方案数
        vector<vector<int>>dp(k+1,vector<int>(n,0));
        dp[0][0]=1;

        for(int i=0;i<k;i++)//控制轮数
        {
            for(auto&e:relation)
            {
                int scr=e[0];//从哪里来
                int des=e[1];//去往哪里

                dp[i+1][des]+=dp[i][scr];
            }
        }

        return dp[k][n-1];
    }
};