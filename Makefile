CC=gcc
AR=ar -rcs
CFLAGS= -Wall -Wextra -g

EXE=graph


all: ${EXE}

${EXE}: main.o libgraps.a
	${CC} ${CFLAGS} -o ${EXE} main.o graph.o heap.o

main.o: main.c graph.h
	${CC} ${CFLAGS} -c main.c

libgraps.a: graph.o heap.o
	${AR} libgraps.a graph.o heap.o

graph.o: graph.c graph.h
	${CC} ${CFLAGS} -c graph.c

heap.o: heap.c heap.h
	${CC} ${CFLAGS} -c heap.c

.PHONY: clean all

clean: 
	rm -f *.o *.so *.a ${EXE}

run:
	./${EXE}

testleak:
	valgrind --check-leak=full ./${EXE}