
MAKEFLAGS += -rR --no-print-directory
RM=@rm -rf a.out *~ *.o *.swp *.sow *~
GCC=@gcc -w 
ECHO=&& echo -n "  CC  " && echo "$P"

all:
	${GCC} -I. thread_semaphore.c lock.c -o thread_semaphore -lpthread ${ECHO} thread_semaphore.c
clean:
	${RM} thread_semaphore

