class Solution {
public:
    int tribonacci(int n) {
        int t0=0;
        int t1=1;
        int t2=1;
        if(n==0)
            return 0;
        if(n<3)
            return n;
        
        int ret=0;
        while(n>2)
        {
            ret=t0+t1+t2;
            t0=t1;
            t1=t2;
            t2=ret;
            n--;
        }

        return ret;

    }
};