225. 用队列实现栈

typedef int QdataType;

typedef struct node{
    QdataType data;
    struct node *next;
}node;

typedef struct queue{
    
    node *head;
    node *tail;
}queue;

void init(queue **qe)
{
    assert(qe);
    *qe=(queue*)malloc(sizeof(queue));//先给结构体开辟空间
    assert(qe);

//都指向空
    (*qe)->head=NULL;
    (*qe)->tail=NULL;
}

void destory(queue *qe)//销毁
{
    assert(qe);
    node *cur=qe->head;

    while(cur)
    {
        node *next=cur->next;
        free(cur);
        cur=next;
    }
    free(qe);
}

bool empty(queue *qe)
{
    if(!qe->head)
    return true;
    return false;
}

void push(queue *qe,int x)
{
    assert(qe);
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=x;
    newnode->next=NULL;

    if(qe->head==NULL)//当前队列为空
    {
        qe->head=newnode;
        qe->tail=newnode;
    }
    else
    {
        qe->tail->next=newnode;
        qe->tail=newnode;
    }
}

void pop(queue *qe)
{
    assert(qe);
    assert(qe->head!=NULL);

    node *next=qe->head->next;
    free(qe->head);
    qe->head=next;
}

QdataType front(queue *qe)
{
    assert(qe&&qe->head);

    return qe->head->data;
}

QdataType back(queue *qe)
{
    assert(qe&&qe->head);

    return qe->tail->data;
}

int size(queue *qe)
{
    assert(qe);
    node *cur=qe->head;
    int count=0;

    while(cur)
    {
        cur=cur->next;
        count++;
    }
    return count;

}

typedef struct {
    queue *q1;
    queue *q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *obj;
    obj=(MyStack*)malloc(sizeof(MyStack));

    init(&(obj->q1));
    init(&(obj->q2));
    return obj;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
        push(obj->q1,x);    
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {

        while(size(obj->q1)>1)
        {
            int num=front(obj->q1);
            push(obj->q2,num);
            pop(obj->q1);
        }
    //q1中剩1个
    int num=front(obj->q1);
    pop(obj->q1);

    while(!empty(obj->q2))//回到q1
    {
        push(obj->q1,front(obj->q2));
        pop(obj->q2);
    }
    return num;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
   return back(obj->q1);
}
bool myStackEmpty(MyStack* obj) {
	return empty(obj->q1) && empty(obj->q2);
}
void myStackFree(MyStack* obj) {
	destory(obj->q2);
	destory(obj->q1);
	free(obj);
	obj = NULL;
}

