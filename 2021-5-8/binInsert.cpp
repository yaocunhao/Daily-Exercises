class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        int count=0;//计数器
        while(m)
        {
            int val=m&1;//得到m的第一位
            m>>=1;
            
            n^=(val<<j+count);
            count++;
        }
        return n;
    }
};