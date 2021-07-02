class Solution {
public:
    int longestPalindrome(string s) {
        //遍历一遍字符串 -> 从中挑取偶数的字符
        if(s.size()==0)
            return 0;
        
        int max=0;
        unordered_map<char,int> mp;

        for(auto&e:s)
        {
            mp[e]++;
            if(mp[e]%2==0)
                max+=2;
        }
        if(max<s.size())//可以有一个单着的字符串
            max++;
        return max;
    }
};