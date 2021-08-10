class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int> dp(nums.size(),0);//dp[i]表示以i结尾时，等差子数组的个数

        int count=0;
        for(int i=2;i<nums.size();i++)
        {
            dp[i]=dp[i-1]+1+count;

            if(nums[i]-nums[i-1] == nums[i-1]-nums[i-2])
            {
                dp[i]=dp[i-1]+1+count;
                count++;
            }
            else
            {
                dp[i]=dp[i-1];
                count=0;
            }
        }
        return dp[nums.size()-1];
    }
};