class Solution {
public:
    void Insert(unordered_multimap<string,string>& map,string &s)
    {
        string copy(s);//预留一份
        sort(s.begin(),s.end());//排序
        map.insert(make_pair(s,copy));//插入map之中
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_multimap<string,string> map;
        for(auto &s:strs)
        {
            Insert(map,s);
        }

        vector<vector<string>> ret;

        string prev;
        vector<string> temp;
        for(auto &e:map)
        {
            if(e.first==prev)//和前面的相等
            {
                temp.push_back(e.second);
            }
            else
            {
                if(!temp.empty())
                    ret.push_back(temp);
                prev=e.first;
                temp.clear();
                temp.push_back(e.second);
            }
        }
        if(!temp.empty())
        {
            ret.push_back(temp);
        }

        return ret;
    }
};