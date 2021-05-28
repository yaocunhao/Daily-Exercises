class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int cur=nums.size()-2;

        while(cur>=0&&nums[cur]>=nums[cur+1])//前面大于后面的
        {
            cur--;
        }

        if(cur<0)//已经是最大数组了
            sort(nums.begin(),nums.end());
        else//表示找到了降序的一个位置
        {
            int pos=nums.size()-1;
            while(nums[pos]<=nums[cur])
            {
                pos--;
            }

            swap(nums[cur],nums[pos]);
            reverse(nums.begin()+cur+1,nums.end());
        }
        
    }
};