CC=gcc -O3

make: grafo.o main.o push-relabel.o
	$(CC) grafo.o main.o push-relabel.o -o pr



grafo.o: grafo.c grafo.h
	$(CC) grafo.c -c -o grafo.o

main.o: main.c
	$(CC) main.c -c -o main.o


push-relabel.o: push-relabel.h grafo.h
	$(CC) push-relabel.c -c -o push-relabel.o


clean:
	rm -f *.o pr
