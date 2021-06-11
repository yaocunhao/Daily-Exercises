class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1=text1.size();
        int len2=text2.size();

        vector<vector<int>>dp(len1+1,vector<int>(len2+1,0));
        //dp[i][j]表示text1的前i个字符和text2的前j个字符中，公共子序列的长度

        for(int i=0;i<len1;i++)
        {
            for(int j=0;j<len2;j++)
            {
                if(text1[i]==text2[j])//当前字符匹配上了
                    dp[i+1][j+1]=dp[i][j] + 1;
                else//当前字符没有匹配上
                    dp[i+1][j+1]=fmax(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[len1][len2];
    }
};