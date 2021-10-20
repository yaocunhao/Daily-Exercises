class Solution {
public:
    int minMoves(vector<int>& nums) {
        //n-1个数加1，反过来就是1个数-1

        bool flag=true;
        int count=0;

        int min=nums[0];
        for(auto &e:nums)
        {
            min=fmin(min,e);
        }
        for(auto&e:nums)
        {
            count+=e-min;
        }

        return count;
    }
};