class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(!q1.empty())
        q1.push(x);
        else
        q2.push(x);

    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {

        if(!q1.empty())
       {
            while(q1.size()>1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int num=q1.front();
        q1.pop();
        return num;
       }

        while(q2.size()>1)
        {
            q1.push(q2.front());
            q2.pop();
        }
        int num=q2.front();
        q2.pop();
        return num;
    }
    
    /** Get the top element. */
    int top() {
        if(!q1.empty())
        return q1.back();
        return q2.back();

    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty()&&q2.empty();

    }

    queue<int> q1;
    queue<int >q2;
};

