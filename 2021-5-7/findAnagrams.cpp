### 解题思路
两个数组分被记录p、s中相对位置的字符出现的次数
用一个滑动窗口保存出现的字符、新字符入队时，s的统计数组对应的值+1
pop出去的字符在统计数组之中-1
同时下标sub+1；

### 代码

```cpp
class Solution {
public:

    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        int s_leng=s.size();
        int p_leng=p.size();
        if(s_leng<p_leng)
            return ret;

        //s子串和p数字统计
        vector<int> count_p(26,0);
        vector<int> count_s(26,0);
        for(int i=0;i<p.size();i++)
        {
            count_p[p[i]-'a']++;
            count_s[s[i]-'a']++;
        }

        int sub=0;//下标记录
        if(count_p==count_s)//相等则记录下标
        {
            ret.push_back(sub);
        }
        sub++;

        deque<char> wind(s.begin(),s.begin()+p.size());//滑动窗口
        
        for(int i=p_leng;i<s_leng;i++)
        {
            int index=wind.front()-'a';
            wind.pop_front();
            wind.push_back(s[i]);//入队
            count_s[index]--;
            count_s[s[i]-'a']++;

            if(count_p==count_s)//相等则记录下标
                ret.push_back(sub);

            sub++;
        }

        return ret;
    }
};
```