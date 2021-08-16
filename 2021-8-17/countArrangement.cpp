class Solution {
public:
    void _countArrangement(int n,int &count,vector<bool>&flag,int i)
    {
        if(i>n)
        {
            count++;
            return;
        }
  
        for(int j=1;j<=n;j++)// 可选择的数有 1-n
        {
            if((i%j==0 || j%i==0) && flag[j]==true)
            {
                flag[j]=false;
                _countArrangement(n,count,flag,i+1);
                 flag[j]=true;
            }
        }
    }

    int countArrangement(int n) {
        // 条件翻译 -> 第nums[i] 与i相等 或者 nums[i]是i的倍数 或者 i是nums[i]的倍数
        int count=0;
        vector<bool> flag(n+1,true);
        _countArrangement(n,count,flag,1);
        return count;
    }
};