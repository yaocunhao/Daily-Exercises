class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int max=ranges[0][1];
        for(auto&e:ranges)
            max=fmax(max,e[1]);
        
        vector<int> arr(max+2,0);

    //将对应的位置，起始区间设置为1，后边区间位置设置为-1
        for(auto&e:ranges)
        {
            arr[e[0]]++;
            arr[e[1]+1]--;
        }
    //求前缀和
        for(int i=1;i<arr.size();i++)
        {
            arr[i]+=arr[i-1];
        }
    //判断是否在区间之中
        for(int i=left;i<=right;i++)
        {
            if(i>=arr.size()||arr[i]<1)
                return false;
        }
    
        return true;
    }

};