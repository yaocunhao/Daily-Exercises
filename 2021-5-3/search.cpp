搜索旋转排序数组

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;

        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(target>nums[right])
            {
                if(nums[mid]>target)
                    right=mid-1;
                else if(nums[mid]<target)
                    {
                        if(nums[mid]>nums[right])
                            left=mid+1;
                        else
                            right=mid-1;
                    }
                else
                    return mid;
            }
            else
            {
                if(nums[mid]>target)
                    { 
                        if(nums[mid]<nums[right])
                        right=mid-1;
                        else
                        left=mid+1;
                    }
                else if(nums[mid]<target)
                    left=mid+1;
                else
                    return mid;
            }   
        }
        return -1;

    }
};