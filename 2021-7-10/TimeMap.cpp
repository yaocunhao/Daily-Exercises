class TimeMap {
public:

    /** Initialize your data structure here. */
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        tp.first=timestamp;
        tp.second=value;

        mp[key].push_back(tp);
    }
    
    int BinarySearch(vector<pair<int,string>>&arr,int &time)
    {
        int left=0;
        int right=arr.size()-1;
       while(left<=right)
       {
           int mid=left+(right-left)/2;
           if(arr[mid].first>time)
                right=mid-1;
            else if(arr[mid].first<time)
                left=mid+1;
            else
                return mid;
       }
        return right;
    }
    string get(string key, int timestamp) {

        if(mp[key].size()==0||mp[key][0].first>timestamp)
            return "";
       //由于是按时间顺序插入的，因此arr里面的元素是按时间排好序的
       //找到对应的位置，前面一个位置就是需要找的值
        int mid= BinarySearch(mp[key],timestamp);
        if(mid>=0)
        {
            string ret=mp[key][mid].second;
            return ret;
        }
        return "";
    }

    unordered_map<string,vector<pair<int,string>>> mp;
    pair<int,string> tp;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */