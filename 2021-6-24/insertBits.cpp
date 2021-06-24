class Solution {
public:
    int insertBits(int N, int M, int i, int j) {
        //将N的 i-j位置为0

        for(int k=i;k<=j;k++)
        {
            int num=N&(1<<k);//得到第K位的数为多大
            N-=num;//减去这个数，就是将这个位置，置为0
        }

        return N + (M<<i);
    }
};