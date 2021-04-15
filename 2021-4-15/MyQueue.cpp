class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        _st1.push(x);

    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(_st2.empty())
        {
            while(!_st1.empty())
            {
                _st2.push(_st1.top());
                _st1.pop();
            }
        }
        int num=_st2.top();
        _st2.pop();
        return num;
    }
    
    /** Get the front element. */
    int peek() {
            if(_st2.empty())
        {
            while(!_st1.empty())
            {
                _st2.push(_st1.top());
                _st1.pop();
            }
        }
        return _st2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return _st1.empty()&&_st2.empty();
    }
    stack<int> _st1;
    stack<int> _st2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */