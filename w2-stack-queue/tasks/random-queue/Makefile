all: program

program: main.o randomized-queue.o rnd-queue-iterator.o iterable.o iterator.o
	g++ -o program main.o randomized-queue.o rnd-queue-iterator.o iterable.o iterator.o

main.o: main.cpp
	g++ -c main.cpp

randomized-queue.o: randomized-queue.h

rnd-queue-iterator.o: rnd-queue-iterator.h

iterable.o: ../../dsa/iterable.cpp ../../dsa/iterable.h
	g++ -c ../../dsa/iterable.cpp

iterator.o: ../../dsa/iterator.cpp ../../dsa/iterator.h
	g++ -c ../../dsa/iterator.cpp

clean:
	rm *.o program