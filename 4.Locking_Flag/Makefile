
MAKEFLAGS += -rR --no-print-directory
RM=@rm -rf a.out *~ *.o *.swp *.sow *~
GCC=@gcc -w 
ECHO=&& echo -n "  CC  " && echo "$P"

all:
	${GCC} -I. thread_lock.c lock.c -o thread_lock -lpthread ${ECHO} thread_lock.c
clean:
	${RM} thread_lock

