找到所有数组中消失的数字

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //将数组内的数当作下标，将对应位置的值改为负数，
        //那么还为正数的位置，即为缺失的数
        vector<int> ret;

        for(int i=0;i<nums.size();i++)
        {
            int sub=abs(nums[i])-1;
            nums[sub]=abs(nums[sub])*(-1);//避免重复出现
        }

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
                ret.push_back(i+1);
        }
        return ret;

    }
};