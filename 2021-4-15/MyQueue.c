232. 用栈实现队列

typedef int STDataType;
typedef struct stack{
    int size;
    int capacity;
    STDataType *arr;
}stack;

void StackInit(stack **ps)
{
    stack *node=(stack*)malloc(sizeof(stack));
    assert(node);
    (*ps)=node;
    (*ps)->arr=(STDataType*)malloc(sizeof(STDataType)*2);
    (*ps)->size=0;
    (*ps)->capacity=2;
}

void StackPush(stack *ps,STDataType x)
{
    assert(ps);

    if(ps->size==ps->capacity)
    {
        ps->capacity=2*ps->capacity;
        STDataType *temp=(STDataType*)realloc(ps->arr,sizeof(STDataType)*ps->capacity);
        assert(temp);
        ps->arr=temp;
    }
    ps->arr[ps->size]=x;
    ps->size++;
}

STDataType Stacktop(stack *ps)
{
    assert(ps->size!=0);
    return ps->arr[ps->size-1];
}

void  Stackpop(stack *ps)
{
    assert(ps);

    assert(ps->size!=0);
    ps->size--;
}

bool Stackempty(stack *ps)
{
    assert(ps);

    if(ps->size==0)
    return true;
    return false;
}

STDataType Stacksize(stack *ps)
{
    assert(ps);
    return ps->size;
}

void Stackdestory(stack *ps)
{
    assert(ps);
    ps->size=0;
    ps->capacity=0;
    free(ps->arr);
    ps->arr=NULL;
}


typedef struct {
    stack *st1;
    stack *st2;

} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue *queue=(MyQueue*)malloc(sizeof(MyQueue));
    StackInit(&queue->st1);
    StackInit(&queue->st2);
    return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    StackPush(obj->st1,x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if(Stackempty(obj->st2))
    {
        while(!Stackempty(obj->st1))
        {
            int val=Stacktop(obj->st1);
            Stackpop(obj->st1);
            StackPush(obj->st2,val);
        }
    }
            int num=Stacktop(obj->st2);
        Stackpop(obj->st2);
        return num;


}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
     if(Stackempty(obj->st2))
    {
        while(!Stackempty(obj->st1))
        {
            int val=Stacktop(obj->st1);
            Stackpop(obj->st1);
            StackPush(obj->st2,val);
        }
    }
    return Stacktop(obj->st2);

}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return Stackempty(obj->st1)&&Stackempty(obj->st2);
}

void myQueueFree(MyQueue* obj) {
    Stackdestory(obj->st1);
    Stackdestory(obj->st2);
    free(obj);
    obj=NULL;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/




