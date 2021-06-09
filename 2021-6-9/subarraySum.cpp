class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //设 1 -i 下标的连续数组和为 sum[i]
        //sum[i] - sum[j] =k -> sum[j] = sum[i] - k  
        //即在其中寻找，是否两个连续数组相减 == k
        //此时需要注意的有如下几点
        //1.当sum[i]==sum[j]时、即k为0时 -> 排除一次自身

        unordered_map<int,int> map;
        int prev=0;
        int count=0;

        map[0]=1;
        int val;
        for(auto&e:nums)
        {
            val=prev+e;
            prev+=e;

            auto it=map.find(val-k);
           if(it!=map.end())
            count+=it->second;

            map[val]++;
        }

        return count;
    }
};