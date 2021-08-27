class MedianFinder {
public:
    /** initialize your data structure here. */

    //一个大堆一个小堆
    //小堆的堆顶，是较大元素中最小的一个
    //大堆的堆顶，是较小元素中的最大的一个
    //两者的数量相差不超过1

    //注意点：需要保证小堆的所有元素都大于大堆的元素，因此每个元素入大堆前，都需要与小堆堆顶进行比较
    MedianFinder() {}
    
    void addNum(int num) {
        if(min_heap.empty())//小堆为空，先入小堆
            min_heap.push(num);
        else
        {
          if(min_heap.size() > max_heap.size())//小堆元素多，入大堆
            {
                //新来的元素，大于小堆堆顶，本来入小堆，但是小堆元素较多，因此将num和小堆堆顶进行交换
                if(num>=min_heap.top())
                {
                    min_heap.push(num);
                    num=min_heap.top();
                    min_heap.pop();
                }
                max_heap.push(num);
            }   
        else if(min_heap.size()<max_heap.size())//小堆元素少,入小堆
            {
                //新来元素，小于大堆堆顶，说明应该进入大堆，但是小堆元素少
                if(num<max_heap.top())
                {
                    max_heap.push(num);
                    num=max_heap.top();
                    max_heap.pop();
                }
                min_heap.push(num);
            }
            else//元素一样多
            {
                if(num>=max_heap.top())//大于大堆的堆顶，说明属于较大元素，入小堆
                    min_heap.push(num);
                else
                    max_heap.push(num);
            }
        }
    }
    
    double findMedian() {

        if(min_heap.size()==max_heap.size())//为偶数，各取一个
        {
            double val1=min_heap.top();
            double val2=max_heap.top();
            return (val1+val2)/2;
        }
        else//为奇数，谁多取谁
        {
            if(min_heap.size() > max_heap.size())
                return min_heap.top();
            else
                return max_heap.top();
        }
    }

    priority_queue<int,vector<int>,greater<int>> min_heap;
    priority_queue<int,vector<int>,less<int>> max_heap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */