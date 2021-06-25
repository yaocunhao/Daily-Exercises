class Solution {
public:
    vector<int> findClosedNumbers(int num) {
        //比特位个数相同，又正好大小最接近

        //接近 ->  改变的最少，并且比特位个数要相同
        //变大：将第一个为0的比特位变为1，在这个比特位后的第一个为1的比特位变为0,
        //然后将此位置后面的1。全部挪到靠右边，0全部挪到靠左边

        //变小：将第一个为1的比特位变为0，将这个位置后面的第一个为0的比特位变为1
        //然后将此位置的后面的1全部挪到靠左边，0全部挪到靠右边

        //边界处理：找到的位置不能是符号位

    vector<int> ret(2,-1);
    //1.获取num的比特位情况
        vector<int> arr(32,0);
        for(int i=0;i<32;i++)
        {
            if(num&(1<<i))//当前位不为0
                arr[i]=1;
        }
    
        vector<int>max(arr);

    //2.求变大的数
        int end=-1;

        for(int i=0;i<32;i++)
        {
            if(max[i]==0&&end!=-1&&i!=31)//找到第一个比特位为0的位置
            {
                max[i]=1;
                max[end]=0;
                break;

            }
            else if(max[i]==1)
            {
                end=i;
            }
        }
        if(arr!=max)//没有找到
        {
            //统计 0-end位置1的个数
            int count=0;
            for(int i=0;i<end;i++)
            {
                if(max[i]==1)
                    count++;
            }
            //将所有的1挪到右边
            for(int i=0;i<end;i++)
            {
                if(count!=0)
                {
                    max[i]=1;
                    count--;
                }
                else
                    max[i]=0;
            }
            //取出比特位组成数字
            int n_max=0;
            for(int i=0;i<32;i++)
            {
                int n=max[i];
                n_max|=(n<<i);
            }
            ret[0]=n_max;
        }
    //3.求变小的数
        end=-1;
        vector<int> min(arr);

        for(int i=0;i<32;i++)
        {
            if(min[i]==1&&end!=-1&&i!=31)//找到第一个比特位为1的位置
            {
                min[i]=0;
                min[end]=1;
                break;
            }
            else if(min[i]==0)
            {
                end=i;
            }
        }
        if(arr!=min)//没有找到
        {
             //统计 0-end位置0的个数
            int count=0;
            for(int i=0;i<end;i++)
            {
                if(min[i]==0)
                    count++;
            }
            //将所有的0挪到右边
            for(int i=0;i<end;i++)
            {
                if(count!=0)
                {
                    min[i]=0;
                    count--;
                }
                else
                    min[i]=1;
            }

            //取出比特位组成数字
            int n_min=0;
            for(int i=0;i<32;i++)
            {
                int n=min[i];
                n_min|=(n<<i);
            }
            ret[1]=n_min;
        }
        return ret;
    }
};