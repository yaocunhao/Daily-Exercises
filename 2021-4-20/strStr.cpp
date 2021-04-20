28. 实现 strStr()


class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0)
        return 0;
        if(needle.size()>haystack.size())
        return -1;

    //到此，needle!=0&&haystack,size()>needle.size()

        for(int i=0;i<haystack.size();i++)
        {
            if(haystack.size()-i<needle.size())//剩余长度不够了
                return -1;

            int dst=i;
            int scr=0;
            while(scr<needle.size())
            {
                if(needle[scr]!=haystack[dst])
                    break;
                else
                {
                    scr++;
                    dst++;
                }
            }
            if(scr==needle.size())
            return i;
        }
        return -1;
    }
};