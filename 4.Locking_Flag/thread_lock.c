#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <lock.h>

static struct sharedObj_t
{
  int a;
  int b;
  int c;
}sharedObj;

lock_t lck;

static void *readGlobal(void *arg)
{
  lock(&lck);
  printf("%s : %d\n",__func__,sharedObj.a);
  sleep(1);
  printf("%s : %d\n",__func__,sharedObj.b);
  sleep(1);
  printf("%s : %d\n",__func__,sharedObj.c);
  unlock(&lck);
  return NULL;
}

static void *writeGlobal(void *arg)
{
  lock(&lck);
  sharedObj.a = 10;
  sleep(1);
  sharedObj.b = 20;
  sleep(1);
  sharedObj.c = 30;
  unlock(&lck);
  return NULL;
}

int main(void)
{
  pthread_t threadID1, threadID2;
  int retval;
 
  lock_init(&lck);

  retval = pthread_create(&threadID1, NULL, readGlobal, NULL);
  if(retval != 0)
    perror("Pthread Create : ");
  retval = pthread_create(&threadID2, NULL, writeGlobal, NULL);
  if(retval != 0)
    perror("Pthread Create : ");
  
  retval = pthread_join(threadID1, NULL);
  if(retval != 0)
    perror("Pthread Join : ");

  retval = pthread_join(threadID2, NULL);
  if(retval != 0)
    perror("Pthread Join : ");

  return 0;
}
