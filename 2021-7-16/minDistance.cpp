class Solution {
public:
    int minDistance(string word1, string word2) {
        //dp将字符串word1前i个字符 转换为 word2前j个字符需要的操作数
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,0));

        //将空转成字符串
        for(int i=0;i<word2.size();i++)
        {
            dp[0][i+1]=i+1;
        }
        for(int i=0;i<word1.size();i++)
        {
            dp[i+1][0]=i+1;
        }

        //s1[i] == s[j] -> 当前是相等的 -> 那么操作数等于dp[i][j]
        //s[i]!=s[j] -> 当前不相等 -> fmin(dp[i+1][j],dp[i][j+1]) +1

        for(int i=0;i<word1.size();i++)
        {
            for(int j=0;j<word2.size();j++)
            {
                if(word1[i]==word2[j])
                    dp[i+1][j+1]=dp[i][j];
                else
                    dp[i+1][j+1]=fmin(dp[i+1][j],fmin(dp[i][j],dp[i][j+1])) +1;
            }
        }
        return dp[word1.size()][word2.size()];
    }
};