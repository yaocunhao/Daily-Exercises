class Solution {
public:
    int BinarySearch(vector<int>&arr,int target)
    {
        int left=0;
        int right=arr.size()-1;

        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(arr[mid] == target)
                return mid;
            else if(arr[mid] > target)
                right=mid-1;
            else
                left=mid+1;
        }
        return left;
    }
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> record;
        for(int i=0;i<target.size();i++)
        {
            record[target[i]]=i;
        }

        vector<int> sub;

        for(auto&e:arr)
        {
            if(record.find(e)!=record.end())//arr中的元素在target之中
                sub.push_back(record[e]);//记录下标
        }

        //问题转变为求sub数组的最长递增子序列
        vector<int> larr;
        for(auto&e:sub)
        {
            if(larr.size()==0||e>larr.back())
                larr.push_back(e);
            else
                larr[BinarySearch(larr,e)]=e;//覆盖大于e的最小元素
        }

        return target.size() - larr.size();
    }
};