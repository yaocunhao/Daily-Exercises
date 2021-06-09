class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //设有x个桶子，每个桶子执行的时间为(容量) n+1，不同的元素肯定不在同一个桶子里面
        //所以最少需要的桶子的个数为最大任务的长度
        //如果每个桶子都装满了，则剩余的元素随便插入，如果没装满，则所需时间为 (n+1)*(x-1) + 最后一个桶子剩余的元素
        //因为最后一个桶子不需要进行等待

        //进行次数的统计
        unordered_map<char,int> map;

        for(auto&ch:tasks)
        {
            map[ch]++;
        }

        //求出最大元素的个数，即桶子的个数
        priority_queue<int> heap;
        int sum=0;

        for(auto&e:map)//创建一个大堆
        {
            heap.push(e.second);
            sum+=e.second;//记录总体元素的个数
        }

        int max=heap.top();//获得桶子的个数
        heap.pop();
        sum-=max;//出去最大元素，剩余元素的个数
        int time=0;//所需时间

        //判断桶子是否装满
        if(sum>=max*n)//剩余元素的总量大于所有桶子的总量
        {
            time=max*(n+1) + sum-max*n;//每个桶子时间 + 剩余元素个数
            return time;
        }

        //此时，剩余元素装不满所有的桶子

        int tail=1;
        while(!heap.empty()&&heap.top()==max)//取出来的元素个数，和桶子数相等(则一个桶子一个)
        {
            heap.pop();
            tail++;//最后一个桶子的元素
        }

        sum-=(tail-1)*max;//个数小于桶子个数的元素总量

        int num=sum-(max-1)*(n-tail+1);//最后一个桶子可以分配到的元素


        time=(max-1)*(n+1) + tail;//桶子时间 + 最后一个桶子所需要的时间

        if(num>0)
            time+=num;

        return time;

    }
};