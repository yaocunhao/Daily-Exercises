class UnusualAdd {
public:
    int addAB(int A, int B) {
        int sum=A^B;//相加后的结果
        int carry=A&B;
        carry<<=1;//进制
        
        while(carry)
        {
            int temp=sum^carry;
            carry=carry&sum;
            sum=temp;
            carry<<=1;
        }
        return sum;
    }
};