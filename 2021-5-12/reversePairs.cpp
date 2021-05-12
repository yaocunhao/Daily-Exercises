 数组中的逆序对

class Solution {
public:
    void _Merger(vector<int> &nums,int left,int mid,int right,int &count,vector<int>&arr)
    {
        int begin1=left;
        int end1=mid;
        int begin2=mid+1;
        int end2=right;

        int sub=begin1;
        int sub2=begin2;

        while(begin1<=end1&&begin2<=end2)
        {
            if(nums[begin1]<=nums[begin2])
            {
                arr[sub]=nums[begin1];
                count+=(begin2-sub2);
                begin1++;
            }
            else
            {
                arr[sub]=nums[begin2];
                begin2++;
            }
            sub++;
        }
        while(begin1<=end1)
        {
            arr[sub]=nums[begin1];
            begin1++;
            sub++;
            count+=(begin2-sub2);
        }
        while(begin2<=end2)
        {
            arr[sub]=nums[begin2];
            sub++;
            begin2++;
        }
        for(int i=left;i<=right;i++)
        {
            nums[i]=arr[i];
        }
    }
    void Merger(vector<int> &nums,int left,int right,int &count,vector<int>&arr)
    {
        if(left>=right)
            return ;
        int mid=left+(right-left)/2;
        Merger(nums,left,mid,count,arr);
        Merger(nums,mid+1,right,count,arr);
        _Merger(nums,left,mid,right,count,arr);
    }
    int reversePairs(vector<int>& nums) {
        int count=0;
        vector<int> arr(nums.size(),0);
        Merger(nums,0,nums.size()-1,count,arr);
        return count;

    }
};