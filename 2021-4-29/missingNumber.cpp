0～n-1中缺失的数字


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left=0;
        int right=nums.size();
        
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]==mid)//前面没有乱
                left=mid+1;
            else
                right=mid;
        }
        return right;

    }
};