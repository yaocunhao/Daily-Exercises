class Solution {
public:
    int exchangeBits(int num) {
        //得到奇数和偶数的位置是0还是1
        
        for(int i=0;i<31;i+=2)
        {
            int odd=num&(1<<(i+1));//得到奇数位
            int even=num&(1<<i);//得到偶数位

            if(odd==0&&even==0)//两个位置都为0
                continue;
            
            if((1<<i)==even&&(1<<(i+1)!=odd))//偶数位置为1,奇数位置为0
            {
                num-=even;//偶数位置变为0
                num+=(1<<(i+1));//奇数位置变为1
            }
            else if((1<<i)!=even&&(1<<(i+1)==odd))//偶数位置为0,奇数位置为1
            {
                num+=(1<<i);//偶数位置变为1
                num-=(1<<(i+1));//奇数位置变为0
            }
        }

        return num;
    }
};