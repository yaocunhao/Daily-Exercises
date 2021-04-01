26.删除有序数组中的重复项

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
        return 0;
        
        int prev=0;
        int next=1;
        int ret=1;//最后一个元素的后一个位置

        while(next<nums.size())
        {
            if(nums[prev]!=nums[next])
            {
                nums[ret]=nums[next];
                ret++;
            }
           prev++;
           next++;
        }     

        return ret;

    }
};