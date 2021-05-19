class Solution {
public:
    //建小堆仿函数->greater
    struct greater 
    {
        bool operator()(pair<int,int>x,pair<int,int> y)//根据value值进行建堆
        {
            return x.second>y.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //建立map,统计次数，利用堆获取前K个最大的val
        map<int,int>count_map;//统计数组
        for(auto& e:nums)
        {
            count_map[e]++;//统计每个元素出现的次数
        }
       vector<int>ret;
       auto it=count_map.begin();
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater> heap;

       while(it!=count_map.end())//根据value建K个元素的小堆
       {
           if(heap.size()<k)//小于K个的时候
                heap.push(make_pair(it->first,it->second));
            else
            {
                auto val=heap.top();
                if(it->second>val.second)//大于入堆
                {
                    heap.pop();
                    heap.push(make_pair(it->first,it->second));
                }
            }
            it++;
       }

       while(!heap.empty())
       {
           ret.push_back(heap.top().first);//K值进入返回数组
           heap.pop();
       }

       return ret;

    }
};