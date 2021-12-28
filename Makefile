CC=gcc
AR=ar -rcs
CFLAGS= -Wall -Wextra -g

EXE=graph


all: ${EXE}

${EXE}: 
	${CC} ${CFLAGS} -o ${EXE}

#lib.a: 
#	${AR}

#algorithm.o: 
#	${CC} ${CFLAGS} -c

main.o: main.c graph.o
	${CC} ${CFLAGS} main.c graph.c -o main.o

# graph.o: graph.c graph.h edges.h  nodes.h
# 	${CC} ${CFLAGS} -c graph.c -o graph.o

# nodes.o: nodes.c nodes.h
# 	${CC} ${CFLAGS} -c nodes.c

# edges.o: edges.c edges.h
# 	${CC} ${CFLAGS} -c edges.c

.PHONY: clean all

clean: 
	rm -f *.o *.so *.a ${EXE}

run:
	./${EXE}

testleak:
	valgrind --check-leak=full ./${EXE}