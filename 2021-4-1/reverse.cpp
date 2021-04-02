7.正数反转

class Solution {
public:
    int reverse(int x) {
        int val=0;
        int flag=1;

      int min=(unsigned int)pow(2,31)*-1;

        if(x<0)
        {
            if(x==min)
            return 0;

            flag=-1;
            x*=-1;
        }

        unsigned int max=pow(2,31)-1;
      
        while(x)//全部逆置
        {
            if(val>((max+1)/10))//不管正负都超了
                return 0;
            if(val>max/10&&flag==1)//正数肯定超了，负数不一定
                return 0;

            val*=10;
            if(val>(max+1-x%10))//都超了
            return 0;
            if(val>(max-x%10)&&flag==1)
                return 0;

            val+=x%10;
            x/=10;
        }
         
        return val*flag;

    }
};