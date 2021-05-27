class Solution {
public:
    int countDigitOne(int n) {
        long long count=0;
        long long base=n/10;//位于十位
        long long cur=n%10;//位于个位
        long long index=1;//指数
        long long prev=0;

        while(cur!=0||base!=0)
        {
            if(cur<1)
                count+=base*index;
            else if(cur>1)
                count+=base*index + index;
            else    
                count+=base*index +prev + 1;

            //进行迭代
            prev=cur*index + prev;
            cur=base%10;
            base/=10;
            index*=10;
        }

        return (int)count;
    }
};