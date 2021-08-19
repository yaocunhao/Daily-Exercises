class Solution {
public:
   
    string reverseVowels(string s) {
        int begin=0;
        int end=s.size()-1;
        string judge="aeiouAEIOU";

        while(begin<end)
        {
            while(begin<end && judge.find(s[begin])==string::npos)
                begin++;
            while(begin<end &&judge.find(s[end])==string::npos)
                end--;
            
            swap(s[begin],s[end]);
            begin++;
            end--;
        }
        return s;
    }
};