#include <lock.h>

void lock_init(lock_t *lck)
{
  lck->flag = 0;
}

/* This approach may cause error as its non-atomic and causes race condition */
#if 0
void lock(lock_t *lck)
{
  while(lck->flag != 1)
    lck->flag = 1;
}
#endif

/* Atomic Operation using GNU Macro */
void lock(lock_t *lck)
{
  while(__sync_lock_test_and_set(&lck->flag,1) == 1);
}

void unlock(lock_t *lck)
{
  lck->flag = 0;
}
