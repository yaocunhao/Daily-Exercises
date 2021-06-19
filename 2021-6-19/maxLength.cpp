class Solution {
public:
    bool Judge(string &str)
    {
        unordered_map<char,int> mp;

        for(auto&e:str)
        {
            if(mp[e]==0)
                mp[e]++;
            else
                return false;//出现多次
        }
        return  true;
    }

    void _maxLength(string &ret,vector<string>& arr,int sub,string &temp)
    {
        if(!Judge(temp))//出现重复字符
            return ;

        if(temp.size()>ret.size())//出现了更长的字符
            ret=temp;        

        for(int i=sub;i<arr.size();i++)
        {
            string copy(temp);//先保存一份
            temp+=arr[i];
            _maxLength(ret,arr,i+1,temp);
            temp.swap(copy);//回溯处理
        }
    }

    int maxLength(vector<string>& arr) {
        //首先得判断是否有重复的字符
        //挑选出最长的不含重复字符的最长字符串，返回它的长度
        //利用回溯法，进行字符串的拼接，然后进行判断是否出现重复的字符

        string ret,temp;

        _maxLength(ret,arr,0,temp);
        return ret.size();
    }
};