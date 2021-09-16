class Tire
{
    public:
    Tire()
    :IsEnd(false)
    {
        for(int i=0;i<26;i++)
        {
            next[i]=nullptr;
        }
    }

    void Insert(string &words)
    {
        Tire *node=this;
        for(auto&e:words)
        {
            if(node->next[e-'a']==nullptr)
                node->next[e-'a']=new Tire;
            node=node->next[e-'a'];
        }
        node->IsEnd=true;
    }

//查找全部
    bool search(string &words)
    {
        Tire* node=this;
        for(auto&e:words)
        {
            if(node->next[e-'a']==nullptr)
                return false;
            node=node->next[e-'a'];
        }
        return node->IsEnd;
    }
//查找部分
    bool startWith(string &words)
    {
        Tire *node=this;
        for(auto&e:words)
        {
            if(node->next[e-'a']==nullptr)
                return false;
            node=node->next[e-'a'];
        }
        return true;
    }

    private:
    bool IsEnd;
    Tire* next[26];
};

class Solution {
public:
    void _findWords(unordered_set<string> &ret,vector<vector<char>>& board,Tire &te,string temp,int x,int y)
    {
        if(x<0||x>=board.size()||y<0||y>=board[x].size() || board[x][y]=='0')//超过范围,或者已经走过了
            return;

        temp+=board[x][y];
        if(te.startWith(temp)==false)//利用前缀和进行剪枝
            return;

        if(te.search(temp)==true)//找到了
            ret.insert(temp);

        char c=board[x][y];
        board[x][y]='0';
        _findWords(ret,board,te,temp,x+1,y);
        _findWords(ret,board,te,temp,x-1,y);
        _findWords(ret,board,te,temp,x,y+1);
        _findWords(ret,board,te,temp,x,y-1);
        board[x][y]=c;//回溯，恢复现场
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        //先将所有的单词，放入前缀树中
        //然后从board中，进行查找，利用前缀和进行剪枝
        
        Tire te;
        for(auto&e:words)
        {
            te.Insert(e);//将单词添加到前缀树中
        }
        
        unordered_set<string> st;//利用set进行去重处理
        vector<string> ret;

        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                string temp;
                _findWords(st,board,te,temp,i,j);
            }
        }

        for(auto&e:st)
        {
            ret.push_back(e);
        }
        return ret;
    }
};