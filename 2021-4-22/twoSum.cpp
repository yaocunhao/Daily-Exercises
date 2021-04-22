1. 两数之和

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp(nums.begin(),nums.end());//先保存一份
        vector<int> ret;//下标

        int val1=0;
        int val2=0;

        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++)
        {
            int val=target-nums[i];
            int left=i+1;
            int right=nums.size();

            while(left<right)
            {
                int mid=left+(right-left)/2;
                if(nums[mid]<val)
                    left=mid+1;
                else if(nums[mid]>val)
                    right=mid;
                else
                break;
            }
            if(left<right)
            {
                val1=nums[i];
                val2=val;
                break;
            }
        }
        for(int i=0;i<temp.size()&&ret.size()<2;i++)
        {
            if(temp[i]==val1||temp[i]==val2)
            {
                ret.push_back(i);
            }
        }
        return ret;

    }
};