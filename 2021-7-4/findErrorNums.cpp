class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();//总元素个数
        int sum=n+((n-1)*n/2);//正常情况总和
        vector<int> ret(2,0);

        sort(nums.begin(),nums.end());
        int sum2=0;
        int repeat=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i<nums.size()-1&&nums[i]==nums[i+1])
                    repeat=nums[i];//得到重复的数

            sum2+=nums[i];
        }

        int num= sum + repeat -sum2;//缺失的数

        ret[0]=repeat;
        ret[1]=num;

        return ret;
    }
};