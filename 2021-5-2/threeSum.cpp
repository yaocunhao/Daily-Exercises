class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        int begin=0;
        int end=0;
        sort(nums.begin(),nums.end());//排序

        for(int i=0;i<nums.size();i++)
        {
            if(i>0&&nums[i]==nums[i-1])//去重
                continue;

            int val=nums[i];
            if(val>0)//排好序了，大于0直接返回
            break;
        //nums[begin]+nums[end]==-val;
            val*=-1;
        //双指针查找值
            begin=i+1;
            end=nums.size()-1;
        //防止越界
            if(end>=nums.size())
                break;
            
            while(begin<end)
            {
                int num=nums[begin]+nums[end];
                if(num>val)
                end--;
                else if(num<val)
                begin++;
                else
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[begin]);
                    temp.push_back(nums[end]);
                    ret.push_back(temp);
                    begin++;
                    while(begin<end&&nums[begin]==nums[begin-1])//去重
                    {
                        begin++;
                    }
                }
            }

        }
        return ret;
    }
};