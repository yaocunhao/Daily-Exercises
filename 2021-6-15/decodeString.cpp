class Solution {
public:
    string decodeString(string s) {
        string ret;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='0'&&s[i]<='9')//遇到数字
            {
                 string num_temp;
                while(i<s.size()&&s[i]>='0'&&s[i]<='9')//遇到数字
                {
                    num_temp+=s[i];
                    i++;
                }
                num_st.push(stoi(num_temp));
                i--;//i最后多加了一次
            }
            else if(s[i]=='[')//遇到左括号
            {
                ch_st.push("[");
            }
            else if(s[i]>='a'&&s[i]<='z')//遇到字符串
            {
                string temp;
                while(i<s.size()&&s[i]>='a'&&s[i]<='z')
                {
                    temp+=s[i];
                    i++;
                }
                i--;
                if(num_st.empty())
                    ret+=temp;
                else
                    ch_st.push(temp);
            }
            else//遇到的是]
            {
                //从数字栈中获取数字
                int num=num_st.top();
                num_st.pop();

                //从字符串栈中获取字符串
                string ss;
                while(ch_st.top()!="[")
                {
                    ss=ch_st.top()+ss;//变成正向的
                    ch_st.pop();
                }
                ch_st.pop();//'['出栈

                string str;
                for(int i=0;i<num;i++)
                {
                    str+=ss;
                }

                if(num_st.empty())
                    ret+=str;
                else
                    ch_st.push(str);
            }
        }
        if(!ch_st.empty())
            ret+=ch_st.top();

        return ret;
    }
    stack<int> num_st;//存储数字
    stack<string> ch_st;//存储字符串和符号
};