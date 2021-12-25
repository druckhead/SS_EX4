CC=gcc
AR=ar -rcs
CFLAGS= -Wall -Wextra -g

EXE=graph


all: ${EXE}

${EXE}: 
	${CC} ${CFLAGS} -o ${EXE}

lib.a: 
	${AR}

algorithm.o: 
	${CC} ${CFLAGS} -c 

nodes.o: 
	${CC} ${CFLAGS} -c 

edges.o.o: 
	${CC} ${CFLAGS} -c

.PHONY: clean all

clean: 
	rm -f *.o *.so *.a ${EXE}

run:
	./${EXE}

testleak:
	valgrind --check-leak=full ./${EXE}