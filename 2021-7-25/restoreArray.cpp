class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        //通过哈希表记录每个元素的相邻元素
        //首位的元素只有一个相邻元素、中间的每个每个元素都有两个相邻的元素

    //记录相邻元素
        unordered_map<int,vector<int>> record;
        for(auto&e:adjacentPairs)
        {
            record[e[0]].push_back(e[1]);
            record[e[1]].push_back(e[0]);
        }
    
    //找到头尾，选择一种安放的方法，然后依次往后推即可
        int begin=0;
        int end=0;
        int flag=0;
        for(auto&e:record)
        {
            if(e.second.size()==1)//不是头就是尾
            {
                if(flag==0)
                {
                    begin=e.first;
                    flag=1;
                }
                else
                {
                    end=e.first;
                    break;//首位都找到了
                }
                    
            }
        }

        vector<int> ret;
        ret.push_back(begin);
        int prev=begin;
        while(begin!=end)//首位两个元素不相等
        {
            vector<int> arr=record[begin];
            for(auto&e:arr)
            {
                if(e!=prev)
                {
                    prev=begin;
                    begin=e;//得到相邻的元素
                    break;
                }
            }
            ret.push_back(begin);
        }

        return ret;
    }
};