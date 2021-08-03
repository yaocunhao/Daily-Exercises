class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        //排序后，找到不同的位置即可

        vector<int> copy(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());

        int left=0;
        int right=nums.size()-1;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==copy[i])
                left++;
            else
                break;
        }

        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]==copy[i])
                right--;
            else
                break;
        }

        return right>left?right-left+1:0;
    }
};