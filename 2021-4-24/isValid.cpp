给出一个仅包含字符'(',')','{','}','['和']',的字符串，判断给出的字符串是否是合法的括号序列
括号必须以正确的顺序关闭，"()"和"()[]{}"都是合法的括号序列，但"(]"和"([)]"不合法。


class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return bool布尔型
     */
    bool isValid(string s) {
        stack<char> st;
      for(int i=0;i<s.size();i++)
      {
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
        {if(s[i]=='(')
          s[i]=')';
        else if(s[i]=='{')
          s[i]='}';
        else
          s[i]=']';
         st.push(s[i]);
        }
        else
        {
          if(st.size()==0)
            return false;
          if(st.top()!=s[i])
            return false;
          st.pop();
        }
      }
      if(st.size()!=0)
        return false;
      return true;
    }
};