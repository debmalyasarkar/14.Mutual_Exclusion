#include <stdio.h>
#include <pthread.h>

static int global = 0;

/* Loop 'arg' times to increment 'global' */
/* Higher number of iterations causes more corruption */
static void *threadFunc(void *arg)
{
  int local,loops,jj;
 
  loops = *(int *)arg;

  /* The following code cause Data Access Race Condition */
  for(jj = 0; jj < loops; jj++)
  {
    local = global;
    local++;
    global = local;
  }

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

  /* Ideally should be 2000000 , race condition causes corruption */
  printf("Value = %d\n",global);  
  return 0;
}
