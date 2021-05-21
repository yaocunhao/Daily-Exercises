struct Less
{
    bool operator()(string s1,string s2)
    {
      return s1+s2<s2+s1;
    }
};
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string>arr;
        for(auto&e:nums)
            arr.push_back(to_string(e));
        
        sort(arr.begin(),arr.end(),Less());

        string ret;
        for(auto&e:arr)
        {
            ret+=e;
        }
        return ret;
    }
};