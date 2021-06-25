class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int count=0;
        queue<string> qe;
        string str="0000";
        unordered_set<string> st;
        unordered_set<string> st2;

        for(auto&e:deadends)
        {
            st.insert(e);
        } 

        if(st.find(str)!=st.end())//第一个就是死亡数字
            return -1;
        if(target==str)//第一个就是密码
            return count;
        
        qe.push(str);
        st2.insert(str);
        int size=1;//记录每一层的数字的个数
        while(!qe.empty())
        {
            //从队列之中取出数字
            str=qe.front();
            qe.pop();
            size--;
            if(str==target)
                return count;
            
            //将数字添加到队列之中
            for(int i=0;i<str.size();i++)
            {
                //当前数字+1
                if(str[i]=='9')
                    str[i]='0';
                else
                    str[i]=str[i]+1;
                if(st.find(str)==st.end()&&st2.find(str)==st2.end())//不是锁定数字
                {
                    qe.push(str);
                    st2.insert(str);
                }
                    //恢复原来模样
                    if(str[i]=='0')
                        str[i]='9';
                    else
                        str[i]=str[i]-1;

                //当前数字-1
                if(str[i]=='0')
                    str[i]='9';
                else
                    str[i]=str[i]-1;
                if(st.find(str)==st.end()&&st2.find(str)==st2.end())//不是锁定数字
                {
                    qe.push(str);
                    st2.insert(str);
                }
                    if(str[i]=='9')
                        str[i]='0';
                    else
                        str[i]=str[i]+1;
            }

            if(size==0)//当前层的数字全部用完了
            {
                count++;
                size=qe.size();
            }
        }
        return -1;
    }
};