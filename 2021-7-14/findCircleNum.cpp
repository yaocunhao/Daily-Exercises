class Solution {
public:

class UnionFindSet
{
public:
	UnionFindSet(int size)
	{
		_arr.resize(size, -1);
	}

	int FindRoot(int x)//给定一个下标寻找它的根
	{
		while (_arr[x] >= 0)//大于等于0，表示里面存储的是根的下标
		{
			x = _arr[x];
		}
		return x;
	}

	bool Union(int x1, int x2)//将两个下标对应的根，进行合并
	{
		//找到两个根的位置
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);
		
		if (root1 == root2)
			return false;

		_arr[root1] += _arr[root2];
		_arr[root2] = root1;

		return true;
	}

    int Size()
    {
        int n=0;
        for(auto&e:_arr)
        {
            if(e<0)//为根
            n++;
        }
        return n;
    }

private:
	vector<int> _arr;
};
    int findCircleNum(vector<vector<int>>& isConnected) {
        UnionFindSet uft(isConnected.size());

        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected.size();j++)
            {
                if(isConnected[i][j]==1)
                {
                    uft.Union(i,j);
                }
            }
        }

        return uft.Size();
    }
};