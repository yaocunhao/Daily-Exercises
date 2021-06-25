class Solution {
public:
    bool canPermutePalindrome(string s) {
        if(s.size()<2)
            return true;
        
        //s为偶数，不允许有单词为单，s为奇数允许有一个单词为单
        
        unordered_map<char,int> mp;
        for(auto &e:s)
        {
            if(mp[e]++);
        }

        int signal=1;
        if(s.size()%2==0)
            signal=0;//偶数不允许有单

        for(auto&e:mp)
        {
            if(e.second%2!=0)
            {
                if(signal==0)
                    return false;
                
                signal--;
            }
        }
        return true;
    }
};