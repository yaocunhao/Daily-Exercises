class Solution {
public:
    string maximumTime(string time) {
        string ret;

        for(int i=0;i<time.size();i++)
        {
            if(time[i]=='?')
            {
               if(i==0)
            {
                if(time[1]=='?'||time[1]<'4')
                    ret+="2";
                else    
                    ret+="1";
            }
               else if(i==1)
               {
                   if(ret[0]!='2')
                        ret+="9";
                    else 
                        ret+="3";
               }
               else if(i==3)
                ret+="5";

               else if(i==4)
                ret+="9";
            }
            else
                ret+=time[i];
        }
        return ret;
    }
};