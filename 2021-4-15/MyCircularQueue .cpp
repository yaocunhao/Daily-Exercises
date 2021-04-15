622. 设计循环队列

class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        _arr=new int[k+1];
        _rear=_arr;
        _front=_arr;
        size=k;
    }
    
    bool enQueue(int value) {
        if(isFull())
        return false;

        *_rear=value;
        _rear++;

        if(_rear==_arr+size+1)//越界了
            _rear=_arr;

        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
        return false;

        _front++;
        if(_front==_arr+size+1)
        _front=_arr;

        return true;
    }
    
    int Front() {
        if(isEmpty())
        return -1;
        return *_front;

    }
    
    int Rear() {
        if(isEmpty())
        return -1;

        int *temp=_rear;
        if(_rear==_arr)//处于第一个位置
        temp=_arr+size;
        else
        temp--;
        
        return *(temp);

    }
    
    bool isEmpty() {
        if(_rear==_front)
        return true;
        return false;
    }
    
    bool isFull() {
        int *temp=_rear+1;
        if(temp==_arr+size+1)
            temp=_arr;
        if(temp==_front)
        return true;
        return false;
    }

private:
int *_arr;
int *_front;
int *_rear;
int size;
};

