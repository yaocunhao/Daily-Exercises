12. 整数转罗马数字

class Solution {
public:
    string intToRoman(int num) {
        int val[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        char *str[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        string ret;
        int size=sizeof(val)/sizeof(val[0]);
        for(int i=0;i<size;i++)
        {
            while(num>=val[i])
            {
                ret+=str[i];
                num-=val[i];
            }
        }
        return ret;

    }
};