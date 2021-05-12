子数组异或查询

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        //x(l,r)=x(1,r)^x(1,;l-1);

        vector<int> ret(queries.size(),0);
        vector<int> dp(arr.size(),0);
        dp[0]=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            dp[i]=arr[i]^dp[i-1];
        }

        int sub=0;
       for(int i=0;i<queries.size();i++)
        {
           int left=queries[i][0];
           int right=queries[i][1];

           if(left==0)
            ret[sub]=dp[right];
            else
            ret[sub]=(dp[left-1]^dp[right]);

            sub++;
        }

        return ret;
    }
};