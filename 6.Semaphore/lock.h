#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

typedef struct __lock_t
{
  sem_t sem;
}lock_t;

void lock_init(lock_t *);
void lock(lock_t *);
void unlock(lock_t *);
