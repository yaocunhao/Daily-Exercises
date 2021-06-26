class Solution {
public:

    void bfs(queue<string>&qe,unordered_map<string,int>&mp1,unordered_map<string,int>&mp2,int &count,int &ret)
    {
        int size=qe.size();

        while(size)
        {
            //去除字符串
            string str=qe.front();
            qe.pop();
            size--;

            //添加下一层的字符串
            int sub=0;
            for(int i=0;i<str.size();i++)//找到0的位置
            {
                if(str[i]=='0')
                {
                    sub=i;
                    break;
                }
            }

            if(sub-1>=0&&sub-1!=2)//和左边进行交换
            {
                string left=str;
                left[sub-1]=str[sub];
                left[sub]=str[sub-1];
                
                if(mp2.find(left)!=mp2.end())//在另外一边出现过了
                {
                    ret=count+1+mp2[left];
                    return;
                }
                if(mp1.find(left)==mp1.end())//没有出现过
                {
                    mp1[left]=count+1;
                    qe.push(left);
                }
            }
            if(sub+1<str.size()&&sub+1!=3)//和右边进行交换
            {
               string right=str;
                right[sub+1]=str[sub];
                right[sub]=str[sub+1];
                
                if(mp2.find(right)!=mp2.end())//在另外一边出现过了
                {
                    ret=count+1+mp2[right];
                    return;
                }
                if(mp1.find(right)==mp1.end())//没有出现过
                {
                    mp1[right]=count+1;
                    qe.push(right);
                }
            }
            if(sub-3>=0)//和上面进行交换
            {
               string up=str;
                up[sub-3]=str[sub];
                up[sub]=str[sub-3];
                
                if(mp2.find(up)!=mp2.end())//在另外一边出现过了
                {
                    ret=count+1+mp2[up];
                    return;
                }
                if(mp1.find(up)==mp1.end())//没有出现过
                {
                    mp1[up]=count+1;
                    qe.push(up);
                }
            }
            if(sub+3<str.size())//和下面进行交换
            {
               string down=str;
                down[sub+3]=str[sub];
                down[sub]=str[sub+3];
                
                if(mp2.find(down)!=mp2.end())//在另外一边出现过了
                {
                    ret=count+1+mp2[down];
                    return;
                }
                if(mp1.find(down)==mp1.end())//没有出现过
                {
                    mp1[down]=count+1;
                    qe.push(down);
                }
            }
        }
        count++;
    } 
    int slidingPuzzle(vector<vector<int>>& board) {
        //首先转换成字符串(哈希表无法直接处理二维数组)
        string end_str="123450";
        string str;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<3;j++)
            {
                str+=to_string(board[i][j]);
            }
        }

        if(str==end_str)//相等了，不用进行变化
            return 0;
        
        queue<string> qe1;
        queue<string> qe2;
        unordered_map<string,int>mp1;
        unordered_map<string,int>mp2;
        int count1=0;
        int count2=0;

        qe1.push(str);
        qe2.push(end_str);
        mp1[str]=0;
        mp2[end_str]=0;
        int ret=-1;
        while(!qe1.empty()&&!qe2.empty())//两个都不为空
        {
            if(qe1.size()<qe2.size())
                bfs(qe1,mp1,mp2,count1,ret);
            else
                bfs(qe2,mp2,mp1,count2,ret);
            
            if(ret!=-1)
                return ret;
        }
        return -1;
    }
};