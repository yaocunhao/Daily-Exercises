表示数值的字符串

class Solution {
public:
    bool isNumber(string s) {
        //去前导空格
        //去前导符号
        //去前导点，并且进行标记，点后面不是数字false，
        //去前导e，前面出现e直接false
        //去除完后，如果为空，或者是空格，return false
        //进入while()
        //点只能出现一次、.的前面不能有e

        int sub=0;
        while(sub<s.size()&&s[sub]==' ')
        sub++;

        if(sub<s.size()&&(s[sub]=='+'||s[sub]=='-'))
        sub++;

        int index=0;//记录点的个数
        if(sub<s.size()&&s[sub]=='.')
        {
            if(++sub>=s.size()||s[sub]<'0'||s[sub]>'9')
                return false;
            index++;
        }

        if(sub<s.size()&&(s[sub]=='e'||s[sub]=='E'))
            return false;
        
        if(sub>=s.size()||s[sub]==' ')//前导完毕之后，后面的不能为空格，不能没有
            return false;
        
        int flag=0;//记录e的个数
        while(sub<s.size())
        {
            if(s[sub]=='.')
            {
                if(index!=0)//不是第一次出现
                return false;
                if(flag!=0)//点前面不能有e
                return false;
                index++;
            }
            else if(s[sub]=='e'||s[sub]=='E')
            {
                if(flag!=0||sub+1>=s.size()||((s[sub+1]<'0'||s[sub+1]>'9')&&(s[sub+1]!='-'&&s[sub+1]!='+')))
                    return false;//e不是第一次出现或者后面没有东西

                if(s[sub+1]=='-'||s[sub+1]=='+')
                {
                    sub++;
                    if(sub+1>=s.size())
                    return false;//+ - 后面没东西了
                }
                flag++;
            }
            else if(s[sub]==' ')//后导空格
            {
                while(sub<s.size())
                {
                    if(s[sub]!=' ')
                    return false;
                    sub++;
                }
                break;
            }
            else if(s[sub]<'0'||s[sub]>'9')
            return false;

            sub++;
        }

        return true;

    }
};