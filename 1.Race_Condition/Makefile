
MAKEFLAGS += -rR --no-print-directory
RM=@rm -rf a.out *~ *.o *.swp *.sow *~
GCC=@gcc -w 
ECHO=&& echo -n "  CC  " && echo "$P"

all:
	${GCC} thread_race.c -o thread_race -lpthread ${ECHO} thread_race.c
clean:
	${RM} thread_race

