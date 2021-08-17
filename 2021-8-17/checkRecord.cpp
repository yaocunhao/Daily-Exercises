class Solution {
public:
    bool checkRecord(string s) {
        //A少于两个 -> count记录
        //L不能连续3天

        int count=0;
        int Lcount=0;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='A')
            {
                count++;
                Lcount=0;
                if(count>=2)
                return false;
            }
            else if(s[i]=='L')
            {
                Lcount++;
                if(Lcount>=3)
                    return false;
            }
            else
                Lcount=0;
        }
        return true;
    }
};