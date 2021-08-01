class Solution {
public:
    struct  Less
    {
        bool operator ()(pair<int,int>&x1,pair<int,int>&x2)
        {
            return x1.second<x2.second;
        }
    };
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        //先统计每一行的1的个数，然后进行排序，再选出个数最小的前K个
        //两行相同，先出现的更弱 -> top K 问题 -> 建大堆

        priority_queue<pair<int,int>,vector<pair<int,int>>,Less> heap;
        vector<int> flag;
        for(int i=0;i<mat.size();i++)
        {
            int count=0;
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==1)
                    count++;
                else//此时为0，终止轮循环
                {
                    flag.push_back(count);
                    auto val=make_pair(i,count);
                    if(heap.size()==0||heap.size()<k)
                        heap.push(val);
                    else if(count<heap.top().second)
                    {
                        heap.pop();
                        heap.push(val);
                    }
                    
                    break;
                }
            }
        }

        vector<int> ret;
        while(!heap.empty())
        {
            ret.push_back((heap.top()).first);
            heap.pop();
        }

        return ret;
    }
};