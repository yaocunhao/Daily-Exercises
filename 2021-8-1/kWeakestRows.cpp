class Solution {
public:
    int BinarySearch(vector<int>&arr)
    {
        int left=0;
        int right=arr.size()-1;

        while(left<=right)
        {
            int mid=left+(right-left)/2;

            if(arr[mid]==1)
                left=mid+1;
            else
                right=mid-1;
        }
        return left;
    }
    struct Less
    {
        bool operator ()(pair<int,int>&x,pair<int,int>&y)
        {
            if(x.first < y.first)
                return true;
            else if(x.first == y.first && x.second < y.second)
                return true;
            
            return false;

        }
    };
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

        priority_queue<pair<int,int>,vector<pair<int,int>>,Less> heap;
        int sub=0;
        for(auto&e:mat)
        {
            int count=BinarySearch(e);
            
            if(heap.size()<k)
                heap.push(make_pair(count,sub++));
            else if(heap.size()>=k && count < heap.top().first)
            {
                heap.pop();
                heap.push(make_pair(count,sub++));
            }
            else
                sub++;
        }

        vector<int> ret;
        while(!heap.empty())
        {
            ret.push_back(heap.top().second);
            heap.pop();
        }

        reverse(ret.begin(),ret.end());
        return ret;

    }
};