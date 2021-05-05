乘积最大子数组

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max=nums[0];
        int min=nums[0];

        for(int i=1;i<nums.size();i++)
        {
            int _max=nums[i]*nums[i-1];
            int _min=nums[i]*min;

            min=fmin(_min,fmin(_max,nums[i]));
            nums[i]=fmax(_max,fmax(nums[i],_min));
            max=fmax(max,nums[i]);
        }
        return max;

    }
};