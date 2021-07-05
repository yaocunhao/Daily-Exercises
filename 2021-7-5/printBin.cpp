class Solution {
public:
    string printBin(double num) {
        string ret;
        ret+="0.";

        while(num)
        {
            num*=2;

            if(num<1)
                ret+="0";
            else
            {
                ret+="1";
                num-=1;
            }

            if(ret.size()>32)
                return "ERROR";
        }
        return ret;
    }
};