class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //将单词添加至哈希表中
        unordered_set<string> set;
        for(auto& s:wordDict)
        {
            set.insert(s);
        }

        vector<bool>dp(s.size()+1,false);//dp[i]表示0-i的字符是否可以由字典里的单词构成
        dp[0]=true;

        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j>=0;j--)
            {
                if(dp[i+1])
                    break;//剪枝，避免重复判断
                    
                string temp(s.begin()+j,s.begin()+i+1);
                if(set.find(temp)!=set.end())//可以找到
                {
                    dp[i+1]=dp[i+1]||dp[j];//避免干扰
                }
            }
        }

        return dp[s.size()];
    }
};