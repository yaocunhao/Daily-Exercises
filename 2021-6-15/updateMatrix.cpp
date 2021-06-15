class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>>ret(mat.size(),vector<int>(mat[0].size(),-1));

    //用左边和上边的元素求，当前元素
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==0)
                {
                    ret[i][j]=0;
                    continue;
                }
                else if(i==0&&j==0)
                    continue;
                else if(i==0)//到这里，mat[i][j]肯定不是0
                {
                    if(ret[i][j-1]!=-1)
                        ret[i][j]=ret[i][j-1]+1;
                }
                else if(j==0)
                {
                    if(ret[i-1][j]!=-1)
                        ret[i][j]=ret[i-1][j]+1;
                }
                else
                {
                    int left=ret[i][j-1];
                    int up=ret[i-1][j];
                    
                    if(left!=-1)
                        ret[i][j]=left+1;
                    if(up!=-1)
                    {
                        if(ret[i][j]==-1)
                            ret[i][j]=up+1;
                        else
                            ret[i][j]=fmin(ret[i][j],up+1);
                    }
   
                }
            }
        }
    //用右下的元素进行构造
    int row=mat.size()-1;
    int col=mat[0].size()-1;
    for(int i=row;i>=0;i--)
    {
        for(int j=col;j>=0;j--)
        {
            if(i==row&&j==col)//最右下角
                continue;
            if(ret[i][j]==0||ret[i][j]==1)//当前已经是最小的选择了
                continue;
            if(i==row)
            {
                if(ret[i][j]==-1)
                    ret[i][j]=ret[i][j+1]+1;
                else
                    ret[i][j]=fmin(ret[i][j],ret[i][j+1]+1);
            }
            else if(j==col)
            {
                if(ret[i][j]==-1)
                    ret[i][j]=ret[i+1][j]+1;
                else
                    ret[i][j]=fmin(ret[i][j],ret[i+1][j]+1);
            }
            else
            {
                int right=ret[i][j+1];
                int down=ret[i+1][j];
                if(ret[i][j]==-1)
                {
                    ret[i][j]=fmin(right+1,down+1);
                }
                else
                {
                    ret[i][j]=fmin(ret[i][j],fmin(right+1,down+1));
                }
            }

        }
    }
    return ret;

    }
};