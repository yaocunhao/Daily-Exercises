class StackOfPlates {
public:
    StackOfPlates(int cap) 
        :_cap(cap)
    {}
    
    void push(int val) {//入栈
    if(_cap==0)
        return ;
        int sub=st.size()-1;
        if(sub<0||st[sub].size()==_cap)//没有栈，或者栈满了
        {
            st.resize(st.size()+1);
            sub++;
        }
        st[sub].push(val);
    }
    
    int pop() {
        if(_cap==0)
            return -1;
            
        int sub=st.size()-1;

        if(sub<0)//没有栈
            return -1;
        
        int num=st[sub].top();
        st[sub].pop();

        if(st[sub].empty())//为空
            st.erase(st.begin()+sub);
  
        return num;
    }
    
    int popAt(int index) {//指定栈进行pop操作,index是栈的下标
        if(_cap==0)
            return -1;

        if(index>=st.size())//不存在这个栈
            return -1;
        
        int num=st[index].top();

        st[index].pop();

        if(st[index].empty())//为空删除
            st.erase(st.begin()+index);

        return num;
    }
    vector<stack<int>> st;
    int _cap;
};