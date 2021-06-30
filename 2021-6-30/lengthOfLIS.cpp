class Solution {
public:
    int BinarySerach(vector<int>&arr,int num)
    {
        int left=0;
        int right=arr.size()-1;
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(arr[mid]==num)
                return mid;
            else if(arr[mid]<num)
                left++;
            else
                right--;
        }
        return left;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> arr;

        for(auto&e:nums)
        {
            if(arr.size()==0||e>arr.back())
                arr.push_back(e);
            else
            {
                int sub=BinarySerach(arr,e);
                arr[sub]=e;
            }
        }
        return arr.size();
    }
};