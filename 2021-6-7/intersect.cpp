class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;

        for(auto&e:nums1)
        {
            mp1[e]++;
        }

         for(auto&e:nums2)
        {
            mp2[e]++;
        }

        vector<int> ret;
        for(auto&e:mp2)
        {
            auto it=mp1.find(e.first);
            if(it!=mp1.end())
            {
                int num=fmin(it->second,e.second);//得到有多少个相同的
                for(int i=0;i<num;i++)
                {
                    ret.push_back(e.first);
                }
            }
        }
        return ret;

        return ret;

    }
};