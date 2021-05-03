 跳跃游戏

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()<=1)
        return true;

        int gap=nums[0];//当前可以往前走多远
        int sub=0;//记录当前下标
        while(sub+gap<nums.size()-1) //sub+gap>=nums.size()-1 说明可以到达
        {
            if(gap==0)//当前步伐为0，即B能动
            return false;

            int max=0;
            int _sub=0;
            for(int i=1;i<=gap;i++)//到达下一个位置
            {
                if(i+nums[sub+i]>max)
                {
                    max=i+nums[sub+i];//记录从当前点出发，的最远距离
                    _sub=sub+i;
                }

            }   
           sub=_sub;
           gap=nums[sub];
        }
        return true;

    }
};