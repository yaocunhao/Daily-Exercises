class Solution {
public:
    void Sort(string &str,unordered_map<string,vector<string>> &mp)
    {
        string copy(str);
        sort(copy.begin(),copy.end());//进行排序
        mp[copy].push_back(str);
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //字母相同，排列不同
        //将单词排序之后作为key值，加入map之中
        vector<vector<string>> ret;
        unordered_map<string,vector<string>> mp;
        for(auto&e:strs)
        {
            Sort(e,mp);
        }
        for(auto&e:mp)
        {
            sort(e.second.begin(),e.second.end());
            ret.push_back(e.second);
        }

        return ret;
    }
};