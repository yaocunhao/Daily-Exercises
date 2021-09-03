class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> ret;
        if(k==0)
            return ret;
        //最小的K个数，建立一个大堆
        priority_queue<int> heap;

        for(auto&e:arr)
        {
            if(heap.size()<k)
                heap.push(e);
            else
            {
                if(e<heap.top())
                {
                    heap.pop();
                    heap.push(e);
                }
            }
        }

        while(!heap.empty())
        {
            ret.push_back(heap.top());
            heap.pop();
        }
        return ret;
    }
};