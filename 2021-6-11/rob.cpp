class Solution {
public:
    int rob(vector<int>& nums) {
        //既然首位不能共存，就将其拆分成两个单独的数组
        // 0~n-1 为一个数组  1-n为一个数组 然后分别在两个数组中进行操作，返回其中的最大值

        int  first=0;
        int second=nums[0];
        int third=nums[0];

        for(int i=1;i<nums.size()-1;i++)
        {
            third=fmax(first+nums[i],second);
            first=second;
            second=third;
        }

        if(nums.size()==1)
            return third;

        first=0;
        second=nums[1];
        int third2=nums[1];
        for(int i=2;i<nums.size();i++)
        {
            third2=fmax(first+nums[i],second);
            first=second;
            second=third2;
        }  

        return fmax(third,third2);      
    }
};