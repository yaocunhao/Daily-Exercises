class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int ret=nums[0]+*(--nums.end());

        int begin=1;
        int end=nums.size()-2;

        while(begin < end)
        {
            int sum=nums[begin]+nums[end];
            ret=fmax(ret,sum);
            begin++;
            end--;
        }

        return ret;
    }
};