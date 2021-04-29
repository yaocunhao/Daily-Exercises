在排序数组中查找数字 I

class Solution {
public:
    int _search(vector<int>& nums, int &target)
    {
        int left=0;
        int right=nums.size()-1;

        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(target>nums[mid])
                left=mid+1;
            else if(target<nums[mid])
                right=mid-1;
            else
                left=mid+1;
        }
        return left;
    }
    int search(vector<int>& nums, int target) {
        int R=_search(nums,target);
        if(R<=0||nums[R-1]!=target)
            return 0;
        
        int val=target-1;
        return R-_search(nums,val);

    }
};