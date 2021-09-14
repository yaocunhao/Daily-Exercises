class Solution {
public:

    //短的，字典序大的在前面
    struct Less
    {
        bool operator()(string &s1,string &s2)
        {
            //s1比s2短，排在s2前面
            if(s1.size()<s2.size())
                return true;
            //s1比s2长
            else if(s1.size()>s2.size())
                return false;

            //一样长，字典序大的在前面
            for(int i=0;i<s2.size();i++)
            {
                if(s1[i]>s2[i])
                    return true;
                else if(s1[i]<s2[i])
                    return false;
                else
                    continue;
            }
            return false;
        }
    };
    string findLongestWord(string s, vector<string>& dictionary) {
        //题意：s删除某些字符，得到字典中的最长字符串
        //给定两个指针，一个指向s，一个指向字典
        //先将字典内的字符按照规则排序 -> 长度升序，字典序升序
        string ret;
        sort(dictionary.begin(),dictionary.end(),Less());
        for(int i=0;i<dictionary.size();i++)
        {
            int begin1=0;
            int begin2=0;

            while(begin1<s.size() && begin2<dictionary[i].size())
            {
                if(s[begin1]==dictionary[i][begin2])
                {
                    begin1++;
                    begin2++;
                }
                else//当前不匹配
                    begin1++;
            }

            //后面的指针走完了，表示当前匹配，更新字符串
            if (begin2==dictionary[i].size())
                ret=dictionary[i];
        }
        return ret;
    }
};