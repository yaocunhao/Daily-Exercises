#include <stdio.h>
#include <iostream>
#include <vector>
#include <pthread.h>
using namespace std;
#include <unistd.h>
class Foo
{
  private:
    pthread_mutex_t lock;
    pthread_cond_t cond2;
    pthread_cond_t cond3;
    int _count;
  public:
    Foo(int count=1)
    :_count(count)
    {
      //进行锁和条件变量初始化
      pthread_cond_init(&cond2,nullptr);
      pthread_cond_init(&cond3,nullptr);
      pthread_mutex_init(&lock,nullptr);
    }

    ~Foo()
    {
      pthread_mutex_destroy(&lock);
      pthread_cond_destroy(&cond2);
      pthread_cond_destroy(&cond3);
    }

    void one()
    {
        cout<<"one"<<endl;
        pthread_mutex_lock(&lock);
        _count++;
        pthread_mutex_unlock(&lock);
        pthread_cond_signal(&cond2);
    }

    void two()
    {
      while(1)
      {
        pthread_mutex_lock(&lock);
       if(_count==2)
       {
         cout<<"two"<<endl;
         _count++;
         pthread_cond_signal(&cond3);
         pthread_mutex_unlock(&lock);
         return ;
       }
       else
         pthread_cond_wait(&cond2,&lock);
       }
    }

    void three()
    {
      while(1)
      {
        pthread_mutex_lock(&lock);
        if(_count==3)
        {
          cout<<"three"<<endl;
          pthread_mutex_unlock(&lock);
          return ;        
        }
        else 
          pthread_cond_wait(&cond3,&lock);
    }
  }
};


Foo fo;
pthread_mutex_t lock;
void *Run(void *arg)
{
  int* num=(int*)arg;
  
  if(*num==1)
  fo.one();
  else if(*num==2)
    fo.two();
  else if(*num==3)
    fo.three();

  return nullptr;
}

int main()
{
  pthread_t tid1,tid2,tid3;

  int one,two,three;
  one=1;
  two=2;
  three=3;

  pthread_create(&tid1,NULL,Run,(void*)&one);
  pthread_create(&tid2,NULL,Run,(void*)&two);
  pthread_create(&tid3,NULL,Run,(void*)&three);

  

  pthread_join(tid1,nullptr);
  pthread_join(tid2,nullptr);
  pthread_join(tid3,nullptr);


  return 0;
}
