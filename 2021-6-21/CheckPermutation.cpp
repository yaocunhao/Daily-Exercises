class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if(s1.size()!=s2.size())//先判断长度是否相等
            return false;
        
        unordered_map<char,int> mp;
        //用哈希表记录其中一个字符串中所有字符出现的次数
        for(auto &e:s1)
        {
            mp[e]++;
        }
        //用另外一个字符去哈希表中进行查询
        for(auto&e :s2)
        {
            if(mp[e]==0)
                return false;
            mp[e]--;//出现的次数减1
        }

        return true;

    }
};