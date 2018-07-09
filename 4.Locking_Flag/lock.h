#include <stdio.h>
#include <stdlib.h>

typedef struct __lock_t
{
  int flag;
}lock_t;

void lock_init(lock_t *);
void lock(lock_t *);
void unlock(lock_t *);
