class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        if(board.size()<2)//只有一个点
            return 0;

        //先将二维数组扁平化为一维数组
        vector<int>arr;
        int flag=1;
        for(int i=board.size()-1;i>=0;i--)
        {
            if(flag==-1)
            {
                for(int j=board.size()-1;j>=0;j--)
                    arr.push_back(board[i][j]);
            }
            else
            {
                for(int j=0;j<board.size();j++)
                arr.push_back(board[i][j]);
            }
            
            flag*=-1;
        }

        queue<int>qe;
        unordered_set<int> record;//标记出现过的点

        qe.push(0);
        record.insert(0);

        int count=0;//记录步伐
        int end=board.size()*board.size();//终点
        int size=1;//记录当前层元素个数

        while(!qe.empty())
        {
            int index=qe.front();
            qe.pop();
            size--;

            for(int i=1;i<=6;i++)
            {
                int next=index + i;

                if(arr[next]!=-1)
                    next=arr[next]-1;
                if(record.find(next)==record.end())//没有出现过
                {
                    if(next==end-1)
                        return count+1;

                    record.insert(next);
                    qe.push(next);
                }
            }
            if(size==0)
            {
                count++;
                size=qe.size();
            }
            
        }
        return -1;
    }
};