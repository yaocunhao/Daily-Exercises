class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //前缀和

        unordered_map<int,int> mp; //k值对应的sum(1和0的个数),v值对应的下标，v应该尽可能的小
        int sum=0;
        int max=0;

        for(int i=0;i<nums.size();i++)
        {
            
            if(nums[i]==1)
                sum++;
            else
                sum--;
            
            if(sum==0)
                max=i+1;
            
            if(mp.find(sum)==mp.end())//不存在，则保存(下标应该尽可能的小)
                mp[sum]=i;
            
            if(mp.find((-1)*sum)!=mp.end())//需要找的那个数存在
                max=fmax(max,i-mp[i-sum]+1);  
        }

        return max;
    }
};