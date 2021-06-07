class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //将nums1装入set1(去重)
        //将num2装入set2，然后用set2的元素取set1中去寻找

        unordered_set<int> st1;
        unordered_set<int> st2;

        for(auto&e:nums1)
        {
            st1.insert(e);
        }

         for(auto&e:nums2)
        {
            st2.insert(e);
        }

        vector<int> ret;
        for(auto&e:st2)
        {
            if(st1.find(e)!=st2.end())
                ret.push_back(e);
        }

        return ret;

    }
};