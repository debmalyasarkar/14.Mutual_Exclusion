
MAKEFLAGS += -rR --no-print-directory
RM=@rm -rf a.out *~ *.o *.swp *.sow *~
GCC=@gcc -w 
ECHO=&& echo -n "  CC  " && echo "$P"

all:
	${GCC} thread_sharedRes.c -o thread_sharedRes -lpthread ${ECHO} thread_sharedRes.c
clean:
	${RM} thread_sharedRes

