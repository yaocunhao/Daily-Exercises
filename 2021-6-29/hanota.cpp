class Solution {
public:
    void Move(vector<int>&A,vector<int>&B,vector<int>&C,int size)
    {
        if(size==1)
        {
            C.push_back(A.back());
            A.pop_back();
            return ;
        }
        Move(A,C,B,size-1);
        C.push_back(A.back());
        A.pop_back();
        Move(B,A,C,size-1);

    }
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        int size=A.size();
        Move(A,B,C,size);
    }
};