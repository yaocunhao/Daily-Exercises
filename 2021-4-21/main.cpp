#include"bq.hpp"

pthread_mutex_t lock;
void *PutData(void *arg)
{
  BlockQueue<Test> *q=(BlockQueue<Test>*)arg;
  
  while(1)
  {
    pthread_mutex_lock(&lock);//加锁

    cout<<"thread"<<pthread_self()<<"put data"<<endl;//当前是那个生产者
    Test data;
    
    data.x=rand()%5;
    data.y=rand()%10;

    q->Put(data);//将随机生成的数据插入阻塞队列之中
    
    cout<<"put data:"<<data.x<<"+"<<data.y<<"=?"<<endl;

    pthread_mutex_unlock(&lock);//解锁

    usleep(1);//线程切换是在内核态回用户态时，增加系统调用，加多判断
  }
}

void *GetData(void *arg)
{
  BlockQueue<Test> *q=(BlockQueue<Test>*)arg;

  while(1)
  {
    sleep(1);
    Test data;
    q->Take(data);

    cout<<"get data:"<<data.x<<"+"<<data.y<<"="<<data.x+data.y<<endl;//打印拿到的数据
  }

}

int main()
{
  pthread_t tid1,tid2,tid3,tid4;
  BlockQueue<Test> *q =new BlockQueue<Test>(5);//也可以定义成全局变量
  pthread_mutex_init(&lock,nullptr);//多个生成者，实现互斥




  pthread_create(&tid1,nullptr,GetData,(void*)q);//消费者拿数据
  pthread_create(&tid2,nullptr,PutData,(void*)q);//生产者生产数据
  pthread_create(&tid3,nullptr,PutData,(void*)q);//生产者生产数据
  pthread_create(&tid4,nullptr,PutData,(void*)q);//生产者生产数据

  //等待不关心返回值
  pthread_join(tid1,nullptr);
  pthread_join(tid2,nullptr);
  pthread_join(tid3,nullptr);
  pthread_join(tid4,nullptr);
  

  pthread_mutex_destroy(&lock);
  delete q;

  return 0;
}
