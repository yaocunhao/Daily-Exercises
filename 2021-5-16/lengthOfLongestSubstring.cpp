class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        deque<char>de;//滑动窗口
        vector<int> arr(200,0);//统计数组
        int max=0;//记录最长的长度

        for(int i=0;i<s.size();i++)
        {
            if(arr[s[i]]==0)//表示没有出现过，直接进入滑动窗口
            {
                arr[s[i]]++;
                de.push_back(s[i]);
            }
            else//表示不是第一次出现
            {
                max=fmax(max,de.size());//先将最长的长度保存下来
                while(arr[s[i]]!=0)//不为0说明还没有将该字符删掉
                {
                    arr[de.front()]--;//计数器减1
                    de.pop_front();//删掉
                }
                //此时说明删掉了，再窗口
                    de.push_back(s[i]);
                    arr[s[i]]++;
            }
        }
        max=fmax(max,de.size());
        return max;

    }
};