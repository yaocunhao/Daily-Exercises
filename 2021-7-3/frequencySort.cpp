class Solution {
public:
    string frequencySort(string s) {
        //两个map

        unordered_map<char,int> mp1;
        multimap<int,char>mp2;


        for(auto&e:s)
        {
            mp1[e]++;
        }

        for(auto&e:mp1)
        {
            mp2.insert(make_pair(e.second,e.first));
        }

        string ret;

        for(auto&e:mp2)
        {
            for(int i=0;i<e.first;i++)
            {
                ret+=e.second;
            }
        }

        reverse(ret.begin(),ret.end());
        return ret;

    }
};