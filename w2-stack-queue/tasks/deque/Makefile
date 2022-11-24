all: program

program: main.o deque.o deque-iterator.o generic-node.o iterable.o iterator.o
	g++ -o program main.o deque.o deque-iterator.o generic-node.o iterable.o iterator.o

main.o: main.cpp
	g++ -c main.cpp

deque.o: deque.h

deque-iterator.o: deque-iterator.h

generic-node.o: ../../dsa/generic-node.cpp ../../dsa/generic-node.h
	g++ -c ../../dsa/generic-node.cpp

iterable.o: ../../dsa/iterable.cpp ../../dsa/iterable.h
	g++ -c ../../dsa/iterable.cpp

iterator.o: ../../dsa/iterator.cpp ../../dsa/iterator.h
	g++ -c ../../dsa/iterator.cpp

clean:
	rm *.o program