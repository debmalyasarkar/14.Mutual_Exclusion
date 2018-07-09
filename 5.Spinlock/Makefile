
MAKEFLAGS += -rR --no-print-directory
RM=@rm -rf a.out *~ *.o *.swp *.sow *~
GCC=@gcc -w 
ECHO=&& echo -n "  CC  " && echo "$P"

all:
	${GCC} -I. thread_spinlock.c lock.c -o thread_spinlock -lpthread ${ECHO} thread_spinlock.c
clean:
	${RM} thread_spinlock

