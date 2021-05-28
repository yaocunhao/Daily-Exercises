class Solution {
public:

    struct Less
    {
        bool operator ()(vector<int>&arr1,vector<int>&arr2)
        {
            return arr1[0]<arr2[0];
        }
    };
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<2)//只有一个区间
            return intervals;

        sort(intervals.begin(),intervals.end(),Less());//按左端点进行排序

        vector<vector<int>> ret;
        ret.push_back(intervals[0]);
        int cur=1;
        while(cur<intervals.size())
        {
            if(intervals[cur][0]<=ret.back()[1])
                ret.back()[1]=fmax(intervals[cur][1],ret.back()[1]);
            else
                ret.push_back(intervals[cur]);

            cur++;
        }
        return ret;
    }
};