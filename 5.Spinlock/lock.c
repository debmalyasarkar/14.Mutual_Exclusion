#include <lock.h>

void lock_init(lock_t *lck)
{
  lck->ticket = 0;
  lck->turn   = 0;
}

/* Atomic Operation using GNU Macro */
void lock(lock_t *lck)
{
  int myticket;
  myticket = __sync_fetch_and_add(&lck->ticket,1);
  while(lck->turn != myticket);
}

void unlock(lock_t *lck)
{
  lck->turn   = lck->turn + 1;
}
