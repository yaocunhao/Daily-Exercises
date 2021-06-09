class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;

        unordered_set<int> set;

        for(auto&e:nums)//将所有数据放入哈希表中
        {
            set.insert(e);
        }

        int max_length=0;
        int length=0;

        for(int i=0;i<nums.size();i++)//找连续的序列
        {
            if(set.find(nums[i]-1)!=set.end())//有前驱
                continue;//跳过

            int num=nums[i]+1;
            length=1;
            while(set.find(num)!=set.end())
            {
                length++;
                num++;
            }
            max_length=fmax(max_length,length);
        }

        return max_length;
    }
};