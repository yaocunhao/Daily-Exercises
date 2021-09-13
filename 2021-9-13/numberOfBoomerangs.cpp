class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        //统计每一个点与其它点的距离，并且保存起来

        unordered_map<int,int> record;
        int ans=0;

        for(int i=0;i<points.size();i++)
        {
            record.clear();
            for(int j=0;j<points.size();j++)
            {
                if(i==j)
                    continue;
                
                int x=points[j][0]-points[i][0];
                int y=points[j][1]-points[i][1];
                int len=pow(x,2)+pow(y,2);
                record[len]++;//统计所有距离相等的点
            }

            //统计相等的点的个数
            for(auto&e:record)
            {
                ans+=(e.second*(e.second-1));
            }
        }

    
        return ans;
    }
};