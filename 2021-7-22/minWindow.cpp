class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> record;//记录t中每个字符出现的次数
        int count=t.size();//记录t中元素个数
        for(auto&e:t)
        {
            record[e]++;
        }

        int left=0;//窗口起始位置
        int right=0;//窗口终止位置

        //记录最短位置
        int min_left=0;
        int min_right=0;

        while(right<s.size()||left<right)
        {
            if(count==0)//说明所有的字符都在窗口之中,可以进行窗口的缩减
            {
                //表示当前还没有记录字符串，或者更小
                    if((min_right-min_left==0)||(right-left)<(min_right-min_left))
                    {
                        min_left=left;
                        min_right=right;
                    }

                if(record.find(s[left])!=record.end())//在窗口之中
                {
                    record[s[left]]++;

                    if(record[s[left]]>0)//删除多了,不满足要求了
                        count++;
                }
                
              left++;
            }
            else if(count!=0 && right<s.size())//count！=0 -> 窗口内的字符还没有满足要求
            {
                if(record.find(s[right])!=record.end())//存在于t之中
                {
                    record[s[right]]--;
                    if(record[s[right]]>=0)//表示并没有出现多余的字符，count还是需要减少
                        count--;
                }
                right++;
            }
            else//窗口内的元素已经不满足要求&&right已经走到了最后的位置
                break;
        }

        if(min_right-min_left==0)
            return "";
        
        string ret(s.begin()+min_left,s.begin()+min_right);
        return ret;
    }
};