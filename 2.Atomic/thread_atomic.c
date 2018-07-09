#include <stdio.h>
#include <pthread.h>

static int global = 0;

/* Loop 'arg' times to increment 'global' */
static void *threadFunc(void *arg)
{
  int local,loops,jj;
 
  loops = *(int *)arg;

  /* GNU Macro for Atomic Operation */
  for(jj = 0; jj < loops; jj++)
    __sync_fetch_and_add(&global,1);

  return NULL;    
}

int main(void)
{
  pthread_t threadID1, threadID2;
  int retval, iterations = 1000000;

  retval = pthread_create(&threadID1, NULL, threadFunc, &iterations);
  if(retval != 0)
    perror("Pthread Create : ");
  retval = pthread_create(&threadID2, NULL, threadFunc, &iterations);
  if(retval != 0)
    perror("Pthread Create : ");
  
  retval = pthread_join(threadID1, NULL);
  if(retval != 0)
    perror("Pthread Join : ");

  retval = pthread_join(threadID2, NULL);
  if(retval != 0)
    perror("Pthread Join : ");

  printf("Value = %d\n",global);  
  return 0;
}
