class Solution {
public:
    int multiply(int A, int B) {
        
        int ret=0;
        int bit=0;    
        while(A)
        {
            if(A&1)
                ret+=B<<bit;
            A>>=1;
            bit++;
        }
        return ret;
    }
};