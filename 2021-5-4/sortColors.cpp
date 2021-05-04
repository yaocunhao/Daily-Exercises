颜色分类

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        int index=0;

      while(index<=right)
      {
          if(index>=left&&nums[index]==0)
          {
              swap(nums[left],nums[index]);
              left++;
          }
          else if(nums[index]==2)
          {
              swap(nums[right],nums[index]);
              right--;
          }
          else
            index++;
      }
    }
};