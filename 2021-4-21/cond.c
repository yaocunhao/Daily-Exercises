#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t lock;//创建锁
pthread_cond_t cond;//创建条件变量

void *Run(void *arg)
{
  while(1)
  {
    pthread_cond_wait(&cond,&lock);//一直等待
    printf("i am %s\n",(char*)arg);
  }
}

void *Run2(void *arg)
{
  while(1)
  {
    printf("........i am %s......\n",(char*)arg);
    pthread_cond_signal(&cond);//唤醒等待线程
    sleep(1);
  }
}

int main()
{
  pthread_mutex_init(&lock,NULL);//初始化锁
  pthread_cond_init(&cond,NULL);//初始化条件变量

  //创建线程
  pthread_t tid1,tid2,tid3,tid4,tid5;
  pthread_create(&tid1,NULL,Run2,(void*)"thread1");
  pthread_create(&tid2,NULL,Run,(void*)"thread2");
  pthread_create(&tid3,NULL,Run,(void*)"thread3");
  pthread_create(&tid4,NULL,Run,(void*)"thread4");
  pthread_create(&tid5,NULL,Run,(void*)"thread5");

  //等待线程,不关心返回值
  pthread_join(tid1,NULL);
  pthread_join(tid2,NULL);
  pthread_join(tid3,NULL);
  pthread_join(tid4,NULL);
  pthread_join(tid5,NULL);

  pthread_mutex_destroy(&lock);//销毁锁
  pthread_cond_destroy(&cond);//释放条件变量




  return 0;
}
