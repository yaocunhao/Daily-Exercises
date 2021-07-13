class Solution {
public:
    bool Judge(char c)
    {
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
            return true;
        return false;
    }
    void _letterCasePermutation(vector<string>&ret,string&s,string &temp,int sub)
    {
        if(temp.size()==s.size())
        {
            ret.push_back(temp);
            return;
        }

        for(int i=sub;i<s.size();i++)
        {
            temp+=s[i];
            _letterCasePermutation(ret,s,temp,i+1);//先将当前次添加进去
             temp.erase(temp.size()-1);//回溯

            if(Judge(s[i])==true)//表示可以进行转换
            {
                if(s[i]>='a'&&s[i]<='z')//转变成大写
                    temp+=s[i]-32;
                else
                    temp+=s[i]+32;
                
            _letterCasePermutation(ret,s,temp,i+1);//先将当前次添加进去
                temp.erase(temp.size()-1);//回溯
            }
        }
    }
    vector<string> letterCasePermutation(string s) {
        //每一步都有两个选择 -> 转或者不转
        vector<string> ret;
        string temp;
        _letterCasePermutation(ret,s,temp,0);
        return ret;
    }
};