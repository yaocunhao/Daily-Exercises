整数反转


class Solution {
public:
    int reverse(int x) {
        string str=to_string(x);
        int sub=0;
        int flag=1;

        if(str[sub]=='-')
        {
            sub++;
            flag=-1;
        }
       std::reverse(str.begin()+sub,str.end());
        unsigned int val=pow(2,31);
        int min=val/10;
        int max=(val-1)/10;



        int num=0;
        while(sub<str.size())
        {
            if(flag==-1&&num>min||flag==1&&num>max)
                return 0;
            num*=10;
            int temp=str[sub]-'0';
            num+=temp;
            sub++;
        }
        return num*flag;

    }
};