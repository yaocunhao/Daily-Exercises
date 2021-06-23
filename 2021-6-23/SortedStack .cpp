class SortedStack {
public:
    SortedStack() {

    }
    
    void push(int val) {
        while(!st1.empty()&&val>st1.top())//新来的元素大于栈顶元素
        {
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(val);
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    void pop() {
        if(!st1.empty())
            st1.pop();
    }
    
    int peek() {
        if(st1.empty())
            return -1;
        return st1.top();
    }
    
    bool isEmpty() {
        return st1.empty();
    }
    stack<int> st1;
    stack<int> st2;
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */