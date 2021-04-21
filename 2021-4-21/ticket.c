#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int ticket=10;//票数
pthread_mutex_t lock;//锁必须是临界资源，因为所的线程都必须看到

void *get_ticket(void *arg)
{
  usleep(10000);
  
  while(1)
  {
    pthread_mutex_lock(&lock);//加锁
    if(ticket>0)
    {
      usleep(100);
      printf("thread_%d get_ticket:%d\n",(int)arg,ticket);
      ticket--;
      pthread_mutex_unlock(&lock);//解锁
      usleep(1000);
    }
    else//没有票了
    {
      pthread_mutex_unlock(&lock);
      break;
    }
  }
}

int main()
{
  pthread_mutex_init(&lock,NULL);//初始化锁
  pthread_t tid[3];

  for(int i=0;i<3;i++)//创建线程
  {
    pthread_create(tid+i,NULL,get_ticket,(void*)i);
  }

 for(int i=0;i<3;i++)
 {
   pthread_join(tid[i],NULL);//进行等待,不关心返回值
 }

 pthread_mutex_destroy(&lock);//销毁锁

  return 0;
}
