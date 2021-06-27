class Solution {
public:

void Add(queue<string>&qe,string &str,unordered_map<string,int>&record,int &count,
unordered_set<string> &list)//下一步可以变化的单词加入队列中
    {
        for(int i=0;i<str.size();i++)//每次变化一个字符
        {
            for(int j='a';j<='z';j++)//每种字符25种变化
            {
                if(j==str[i])//没有变化
                    continue;

                char copy=str[i];
                str[i]=j;

                if(list.find(str)!=list.end()&&record.find(str)==record.end())//在字典中&&没有出现过
                {
                    qe.push(str);
                    record[str]=count+1;
                }

                str[i]=copy;//恢复
            }
        }
    }

    void bfs(queue<string>&qe,unordered_map<string,int>&record1,unordered_map<string,int>&record2,int &ret,int &count,unordered_set<string> &list)
    {
        int size=qe.size();
        while(size--)
        {
            string str=qe.front();
            qe.pop();
            if(record2.find(str)!=record2.end())//在另外一边出现过了
            {
                ret=count+record2[str];
                return;
            }
            //添加下一个字符
            Add(qe,str,record1,count,list);
        }
        count ++;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord==endWord)//开始就相等
            return 0;

        unordered_set<string> list;
        for(auto&e:wordList) 
        {
            list.insert(e);//将字符添加到哈希字典之中
        }

        if(list.find(endWord)==list.end())  
            return 0;//尾不在字典之中

        unordered_map<string,int> record1;
        unordered_map<string,int> record2;
        int count1=0;
        int count2=0;
        queue<string>qe1;
        queue<string>qe2;

        //加入字符
        qe1.push(beginWord);
        qe2.push(endWord);
        record1[beginWord]=0;
        record2[endWord]=0;
        int ret=0;
        while(!qe1.empty()&&!qe2.empty())
        {
            if(qe1.size()<=qe2.size())
                bfs(qe1,record1,record2,ret,count1,list);
            else
                bfs(qe2,record2,record1,ret,count2,list);

            if(ret!=0)
                return ret+1;
        }
        return 0;
    }
};