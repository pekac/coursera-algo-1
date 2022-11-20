all: program

program: main.o deque.o deque-iterator.o generic-node.o iterable.o iterator.o
	g++ -o program main.o deque.o deque-iterator.o generic-node.o iterable.o iterator.o

main.o: main.cpp
	g++ -c main.cpp

deque.o: deque.h

deque-iterator.o: deque-iterator.h

generic-node.o: ../../dsa/generic-node.cpp ../../dsa/generic-node.h
	g++ -c ../../dsa/generic-node.cpp

iterable.o: iterable.h

iterator.o: iterator.h

clean:
	rm *.o deque