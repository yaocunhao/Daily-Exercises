class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int div=pow(10,9)+7;
        //两数之和的范围为： [0,2^21]

        unordered_map<int,int> mp;
        int count=0;
        for(auto&e:deliciousness)
        {
            for(int i=0;i<22;i++)
            {
                int val=pow(2,i) - e;//得到另外一个数
                if(mp.find(val)!=mp.end())
                {
                    count=(count+mp[val])%div;
                }
            }

            mp[e]++;//统计所有数字出现的次数
        }

        return count;
    }
};