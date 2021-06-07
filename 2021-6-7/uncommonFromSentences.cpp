class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
    //题意转换 -> 两个句子中，只出现一次的单词
    //用哈希表进行统计 -> 并且将只出现一次的返回即可

        vector<string> ret;
        unordered_map<string,int> mp;

        if(!s1.empty())//不为空则先加个空格
            s1+=' ';
        s1+=s2;

        if(s1.empty())
            return ret;
        
        //此时s1最少有一个单词
        size_t pos1=0;
        size_t pos2=s1.find(' ');


        while(pos2!=string::npos)
        {
            string temp(s1.begin()+pos1,s1.begin()+pos2);
            mp[temp]++;//添加至mp之中

            pos1=pos2+1;//来到下一个单词的起始处
            pos2=s1.find(' ',pos1);//从pos1处开始寻找下一个空格
        }

        //此时，还剩下一个单词没有添加
        mp[string(s1.begin()+pos1,s1.end())]++;

        for(auto&e:mp)
        {
            if(e.second==1)//只出现一次的
            ret.push_back(e.first);
        }

        return ret;

    }
};