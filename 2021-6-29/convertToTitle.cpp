class Solution {
public:
    string convertToTitle(int columnNumber) {
        //26进制题目
        int n=columnNumber;
        string ret;
        while(n)
        {
            n--;
            ret+=n%26+'A';
            n/=26;
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};