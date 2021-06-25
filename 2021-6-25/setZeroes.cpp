class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

    unordered_set<int> row;//记录应该清空的行
    unordered_set<int> col;//记录应该清空的列    

    //将需要清空的行和列记录下来
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        //将行进行清空
        for(auto&e:row)
        {
           for(int i=0;i<matrix[0].size();i++)
           {
               matrix[e][i]=0;
           }
        }
        //将所在列进行情况
        for(auto&e:col)
        {
            for(int i=0;i<matrix.size();i++)
            {
                matrix[i][e]=0;
            }
        }
    }
};