#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

static struct sharedObj_t
{
  int a;
  int b;
  int c;
}sharedObj;

static void *readGlobal(void *arg)
{
  printf("%s : %d\n",__func__,sharedObj.a);
  sleep(1);
  printf("%s : %d\n",__func__,sharedObj.b);
  sleep(1);
  printf("%s : %d\n",__func__,sharedObj.c);
  return NULL;
}

static void *writeGlobal(void *arg)
{
  sharedObj.a = 10;
  sleep(1);
  sharedObj.b = 20;
  sleep(1);
  sharedObj.c = 30;
  return NULL;
}

int main(void)
{
  pthread_t threadID1, threadID2;
  int retval;

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
