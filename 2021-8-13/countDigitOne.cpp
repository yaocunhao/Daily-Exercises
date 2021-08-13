class Solution {
public:
    int countDigitOne(int n) {
        long long cur=n%10;
        long long base=n/10;
        long long count=0;//计数器
        long long index=1;//指数
        long long prev=0;//记录cur后面的数
        while(base||cur)
        {
            if(cur<1)
                count+=base*index;
            else if(cur==1)
                count+=base*index+prev+1;
            else
                count+=base*index+index;
            
            prev=cur*index+prev;
            cur=base%10;
            base/=10;
            index*=10;
        }

        return count;

    }
};