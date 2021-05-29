class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());//排序
        int ret=nums[0]+nums[1]+nums[2];

        int mid=1;
        while(mid<nums.size()-1)//确定中心点
        {
            int left=mid-1;
            int right=mid+1;

            while(left>=0&&right<nums.size())
            {
                int num=nums[left]+nums[right]+nums[mid];
                if(num==target)//正好合适
                    return target;

                if(abs(target-num)<abs(target-ret))//获取更加接近的值
                    ret=num;
                
                if(num<target)//增大num
                    right++;
                else//减小num
                    left--;
            }
            mid++;//更换中心点
        }

        return ret;
    }
};