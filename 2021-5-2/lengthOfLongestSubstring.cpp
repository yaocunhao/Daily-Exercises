无重复字符的最长子串

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int arr[256]={0};
        deque<char> wind;
        int max=0;

        for(int i=0;i<s.size();i++)
        {
            if(arr[s[i]]==0)//滑动窗口之中没有该字符，可以入队
            {
                arr[s[i]]++;
                wind.push_back(s[i]);
            }
            else//表示窗口之中，已有该字符
            {
                max=fmax(max,wind.size());//记录当前的最大元素个数
                while(wind.front()!=s[i])
                {
                    arr[wind.front()]--;
                    wind.pop_front();//删除、出队
                }
                wind.pop_front();
                wind.push_back(s[i]);//入队
            }
        }

        max=fmax(max,wind.size());
        return max;
    }
};