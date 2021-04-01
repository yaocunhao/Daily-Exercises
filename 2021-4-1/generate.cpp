118杨晖三角
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //arr[i][j]=arr[i-1][j]+arr[i-1][j-1]

        vector<vector<int>> ret(numRows,vector<int>());
      //  ret.resize(numRows,vector<int>());//numrows行

        for(size_t i=0;i<ret.capacity();i++)
        {
            ret[i].resize(i+1,0);//第几行，就有几个数字

            //第一位和左后一位的数字都是1
            (*ret[i].begin())=1;
            *(ret[i].end()-1)=1;
        }

        for(size_t i=0;i<numRows;i++)
        {
            for(size_t j=0;j<ret[i].size();j++)
            {
                if(ret[i][j]==0)
                ret[i][j]=ret[i-1][j]+ret[i-1][j-1];
            }
        }

        return ret;

    }
};