class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()==1)
            return 1;
        
        int sub=0;//新的字符串的位置
        int count=1;//记录重复字符串的个数
        for(int i=1;i<chars.size();i++)
        {
            if(chars[i]!=chars[i-1])//当前字符串和前面的字符串不相等
            {
                //记录前面的字符串
                chars[sub++]=chars[i-1];
                if(count==1)//只有一个字符
                    continue;

                //多个字符，转成字符串并且填入到数组之中                
                string str=to_string(count);
                for(auto&e:str)
                {
                    chars[sub++]=e;
                }
                count=1;
            }
            else//当前字符和前面的字符相等
                count++;
        }

        //处理最后一个字符.
        chars[sub++]=*(--chars.end());

        if(count==1)
            return sub;
        
        string str=to_string(count);
        for(auto&e:str)
        {
            chars[sub++]=e;
        }
        return sub;
    }
};