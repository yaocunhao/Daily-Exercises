class Solution {
public:
    void _combinationSum(vector<int> &arr,int target,vector<vector<int>> &ret,vector<int> temp,int sum,int sub)
    {
        if(sum==target)//当前满足组合条件
        {
            ret.push_back(temp);
            return;
        }
        if(sum>target)//全部都是正整数
            return;
        
        for(int i=sub;i<arr.size();i++)
        {
            temp.push_back(arr[i]);
            sum+=arr[i];
            _combinationSum(arr,target,ret,temp,sum,i);
            //回溯
            sum-=arr[i];
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //从无重复元素数组中选出数字来组成target，返回所有可能的组合
        //选元素时，每个元素可以重复进行选取

        sort(candidates.begin(),candidates.end());//进行升序排列
        vector<vector<int>> ret;
        vector<int> temp;
        int sum=0;
        _combinationSum(candidates,target,ret,temp,sum,0);
        return ret;

    }
};