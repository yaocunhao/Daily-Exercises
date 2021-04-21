#pragma once
#include <iostream>
#include <queue>
#include <pthread.h>
using namespace std;
#include <unistd.h>

class Test
{
  public:
  int x;
  int y;

};

template<class T>
class BlockQueue
{
  private:
    queue <T> _q;//阻塞队列
    size_t _cap;//容量
    pthread_mutex_t lock;//锁
    pthread_cond_t p_cond;//生产者条件变量
    pthread_cond_t c_cond;//消费者条件变量

  public:

    BlockQueue(size_t cap)
      :_cap(cap)
    {
      pthread_mutex_init(&lock,nullptr);
      pthread_cond_init(&p_cond,nullptr);
      pthread_cond_init(&c_cond,nullptr);
    }

    ~BlockQueue()
    {
      pthread_mutex_destroy(&lock);
      pthread_cond_destroy(&p_cond);
      pthread_cond_destroy(&c_cond);
    }

    void LockQueue()
    {
      pthread_mutex_lock(&lock);
    }

    void unLockQueue()
    {
      pthread_mutex_unlock(&lock);
    }

    bool Full()
    {
      return _q.size()>=_cap;//满了
    }

    bool Empty()
    {
      return _q.empty();
    }
    void WakeUpConsumer()
    {
      cout<<"wake up consemer.....\n";
      pthread_cond_signal(&c_cond);
    }
    void WakeUpProducter()
    {
      cout<<"wake up producter......\n";
      pthread_cond_signal(&p_cond);
    }
    void ConsumerWait()
    {
      cout<<"consumer wait.....\n";
      pthread_cond_wait(&c_cond,&lock);
    }
    void ProducterWait()
    {
      cout<<"producter wait.......\n";
      pthread_cond_wait(&p_cond,&lock);
    }


    void Put(const T &data)//放数据
    {
      LockQueue();//加锁
      
      while(Full())//满起自己，通知消费者
      {
        WakeUpConsumer();//队列满了，唤醒消费者
        ProducterWait();//自己挂起
      }
        _q.push(data);

      unLockQueue();//解锁
    }

    void Take(T &data)//拿数据,输出型参数
    {
      LockQueue();

      while(Empty())//使用while防止异常、没有挂起
      {
        WakeUpProducter();//唤醒生产者
        ConsumerWait();//自己挂起
      }

      data=_q.front();
      _q.pop();

      unLockQueue();
    }
};
