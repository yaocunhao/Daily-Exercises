比特位计数

class Solution {
public:
    vector<int> countBits(int num) {
        //计数的0比前面的偶数多一个
        //偶数的0，和右移一位之后的数字是一样的
        //即i/2，因为偶数的第一个比特位为0，右移即是/2行为

        vector<int> ret(num+1,0);
        if(num==0)
        return ret;

        for(int i=1;i<=num;i++)
        {
            if(i%2!=0)//为奇
            ret[i]=ret[i-1]+1;
            else//为偶
            {
                ret[i]=ret[i/2];
            }
        }
        return ret;
        
    }
};