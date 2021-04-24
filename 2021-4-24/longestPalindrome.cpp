//最长回文子串

中心法：
class Solution {
public:
    string longestPalindrome(string s) {
        int left,right;
        string str;
        for(int i=0;i<s.size();i++)
        {
            left=right=i;//确定中心
            
            while(left>=0&&s[left]==s[i])
                left--;//相同的永远是回文串
            while(right<s.size()&&s[right]==s[i])
                right++;
            
            while(left>=0&&right<s.size()&&s[left]==s[right])//左右两边相同是回文串
                {
                    left--;
                    right++;
                }
            //此时左右两边不相同，即不是回文串了
            if(right-left-1>str.size())//当前回文串大于保存的
            {
                string temp(s.begin()+1+left,s.begin()+right);
                str=temp;
            }
        }
        return str;

    }
};