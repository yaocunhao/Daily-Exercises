不同的二叉搜索树

class Solution {
public:
    int numTrees(int n) {
        vector<int> ret(n+1,0);
        ret[0]=1;//0棵树时，为空时一种情况
        ret[1]=1;//一颗树时一种情况

        if(n<2)
        return ret[n];
        
        ret[2]=2;//两棵树时两种情况

        // ret[i]=ret[i-1]*ret[0]+ret[i-2]*ret[1] +....+ ret[0]*ret[i-1]

        for(int i=3;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                ret[i]+= ret[j]*ret[i-j-1];
            }
        }
        return ret[n];
    }