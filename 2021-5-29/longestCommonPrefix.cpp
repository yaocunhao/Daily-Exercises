class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";

        string str(strs[0]);
        int len=0;//标记匹配的长度

        for(auto&e:strs)
        {
            if(e[0]!=str[0])//第一个字符就不匹配
                return "";
            else//匹配了
            {
                int count=0;//记录匹配的单词个数
                for(int i=0;i<e.size();i++)
                {
                    if(i<str.size()&&e[i]==str[i])
                    {
                        count++;
                    }
                    else
                        break;
                }
                //选取最短了
                if(len==0)
                    len=count;
                else
                    len=fmin(len,count);
            }
        }
       string ret(str.begin(),str.begin()+len);
        return ret;
    }
};