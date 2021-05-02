class Solution {
public:
    int romanToInt(string s) {
        int num[127]={0};
        string str("IVXLCDM");

        for(auto &e:str)
        {
            switch(e)
            {
                case 'I':num[e]=1;
                break;
                case 'V':num[e]=5;
                break;
                case 'X':num[e]=10;
                break;
                case 'L':num[e]=50;
                break;
                case 'C':num[e]=100;
                break;
                case 'D':num[e]=500;
                break;
                case 'M':num[e]=1000;
                break;
            }
        }
  
        //  char I='I';
        //  char V='V';
        //  char X='X';
        //  char L='L';
        //  char C='C';
        //  char D='D';
        //  char M='M';

        // num[I]=1;
        // num[V]=5;
        // num[X]=10;
        // num[L]=50;
        // num[C]=100;
        // num[D]=500;
        // num[M]=1000;

        int sum=0;

        for(int i=0;i<s.size();i++)
        {
            if(i+1<s.size())//后面还有字符
            {
                if(num[s[i+1]]>num[s[i]])//后面的字符对应的数字大于前面的字符
                sum-=num[s[i]];
                else
                sum+=num[s[i]];
            }
            else//后面没有字符
            sum+=num[s[i]];
        }
        return sum;
    }
};