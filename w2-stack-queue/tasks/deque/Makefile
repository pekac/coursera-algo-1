all: program

program: generic-node.o deque-iterator.o deque.o main.o  
	g++ -o program main.o deque.o deque-iterator.o generic-node.o

generic-node.o: ../../dsa/generic-node.cpp ../../dsa/generic-node.h
	g++ -c ../../dsa/generic-node.cpp

deque-iterator.o: deque-iterator.h

deque.o: deque.h

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o deque