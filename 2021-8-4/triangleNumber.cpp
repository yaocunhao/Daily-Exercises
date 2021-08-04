class Solution {
public:
    int BinarySearch(vector<int>&arr,int start,int target)
    {
        int left=start;
        int right=arr.size()-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;

            if(arr[mid]>=target)//第三条边太大
                right=mid-1;
            else
                left=mid+1;
        }
        return left-start;
    }
    int triangleNumber(vector<int>& nums) {
        //组成三角形的三条边的规则：
        //两边之和大于第三边 -> a+b>c a+c>b a+c >a

        //排序之后 a<= b <=c -> 即只需要判断a+b > c ，即找c的位置即可 

        if(nums.size()<3)
            return 0;
            
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<nums.size()-2;i++)//第一条边
        {
            for(int j=i+1;j<nums.size();j++)//第二条边
            {
                int sum=nums[i]+nums[j];
                count+=BinarySearch(nums,j+1,sum);
            }
        }

        return count;
    }
};