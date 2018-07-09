#include <lock.h>

void lock_init(lock_t *lck)
{
  sem_init(&lck->sem,0,1);
}

/* Atomic Operation using GNU Macro */
void lock(lock_t *lck)
{
  sem_wait(&lck->sem);
}

void unlock(lock_t *lck)
{
  sem_post(&lck->sem);
}
