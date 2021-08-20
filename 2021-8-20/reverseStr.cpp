class Solution {
public:
    string reverseStr(string s, int k) {
        int begin=0;
        while(begin+2*k<s.size())
        {
            reverse(s.begin()+begin,s.begin()+begin+k);
            begin+=2*k;
        }
        if(s.size()-begin > k)
            reverse(s.begin()+begin,s.begin()+begin+k);
        else
            reverse(s.begin()+begin,s.end());

        return s;
    }
};