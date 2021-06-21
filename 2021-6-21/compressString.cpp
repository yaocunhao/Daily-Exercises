class Solution {
public:
    string compressString(string S) {
        if(S.size()==0)
            return S;

        string ret;
        ret+=S[0];

        int count=1;
        for(int i=1;i<S.size();i++)
        {
            if(S[i]==S[i-1])//相等
                count++;
            else//不相等，将数字添加进去，并且添加新的字符起始位置
            {
                ret+=to_string(count);
                ret+=S[i];
                count=1;
            }
        }
        //最后一次的数字肯定没有添加进去
        ret+=to_string(count);

        if(ret.size()<S.size())
            return ret;
            return S;
    }
};