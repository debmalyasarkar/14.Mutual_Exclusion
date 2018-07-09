
MAKEFLAGS += -rR --no-print-directory
RM=@rm -rf a.out *~ *.o *.swp *.sow *~
GCC=@gcc -w 
ECHO=&& echo -n "  CC  " && echo "$P"

all:
	${GCC} thread_atomic.c -o thread_atomic -lpthread ${ECHO} thread_atomic.c
clean:
	${RM} thread_atomic

