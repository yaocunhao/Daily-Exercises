class Solution {
public:
    class UnionFindSet
    {
    private:
        vector<int> arr;
    public:
        UnionFindSet(int n)
        {
            arr.resize(n,-1);
        }

        int FindRoot(int x)//寻找根
        {
            while(arr[x]>=0)//表示不是根
            {
                x=arr[x];
            }
            return x;
        }

        bool Union(int x,int y)
        {
            int root1=FindRoot(x);
            int root2=FindRoot(y);
            if(root1==root2)
            return false;

            arr[root1]+=arr[root2];
            arr[root2]=root1;
            return true;
        }
    };
    bool equationsPossible(vector<string>& equations) {
        //将相等的都放入一个集合之中
        //然后判断不相等的在不在一个集合-> 根相不相同

        UnionFindSet ufs(26);

        for(auto&e:equations)
        {
            if(e[1]=='=')
            ufs.Union(e[0]-'a',e[3]-'a');
        }
        for(auto&e:equations)
        {
            if(e[1]!='=')
            {
                int root1=ufs.FindRoot(e[0]-'a');
                int root2=ufs.FindRoot(e[3]-'a');
                if(root1==root2)
                    return false;
            }
        }
      return true;
    }
};