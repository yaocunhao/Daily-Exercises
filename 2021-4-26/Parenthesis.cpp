class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        if(n==0)
            return true;
        if(n%2!=0)
            return false;
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            if(A[i]!='('&&A[i]!=')')
                return false;
            
            if(A[i]=='(')
                count++;
            else
                count--;
            if(count<0)
                return false;
        }
        if(count==0)
            return true;
        return false;
    }
};