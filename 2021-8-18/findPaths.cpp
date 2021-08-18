class Solution {
public:
long long _findPaths(int m,int n,int maxMove,int x,int y,int sub,vector<vector<vector<long long>>>&dp,int mod)
    {
        if(sub>maxMove)//超出步伐数
            return 0;
        if(x<0||x>=m||y<0||y>=n)//越界了
            return 1;
        if(dp[sub][x][y]!=-1)
            return dp[sub][x][y];
        
        return dp[sub][x][y]=
        (_findPaths(m,n,maxMove,x+1,y,sub+1,dp,mod)+
        _findPaths(m,n,maxMove,x-1,y,sub+1,dp,mod)+
        _findPaths(m,n,maxMove,x,y+1,sub+1,dp,mod)+
        _findPaths(m,n,maxMove,x,y-1,sub+1,dp,mod))%mod;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int mod=pow(10,9)+7;

        //dp[k][i][j] 表示在[i,j]位置，步伐为K时的次数
        vector<vector<vector<long long>>> dp(maxMove+1,vector<vector<long long>>(m,vector<long long>(n,-1)));
        return _findPaths(m,n,maxMove,startRow,startColumn,0,dp,mod);
    }
};