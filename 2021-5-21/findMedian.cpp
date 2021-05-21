class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() 
    {}
    
    void addNum(int num) {
        if(min_heap.size()==max_heap.size())
        {
            max_heap.push(num);
            int temp=max_heap.top();
            max_heap.pop();
            min_heap.push(temp);
        }
        else
        {
            min_heap.push(num);
            int temp=min_heap.top();
            min_heap.pop();
            max_heap.push(temp);
        }
    }
    
    double findMedian() {
        if(min_heap.size()==max_heap.size())
            return min_heap.top()/2+max_heap.top()/2;
        else
            return min_heap.size()>max_heap.size()?min_heap.top():max_heap.top();
    }

    priority_queue<double,vector<double>,greater<double>> min_heap;//小堆
    priority_queue<double,vector<double>,less<double>> max_heap;//大堆
};