all: deque

deque: generic-node.o deque-iterator.o deque.o main.o  
	g++ -o deque main.o deque.o deque-iterator.o generic-node.o

generic-node.o: ../../dsa/generic-node.cpp ../../dsa/generic-node.h
	g++ -c ../../dsa/generic-node.cpp

deque-iterator.o: deque-iterator.cpp deque-iterator.h 
	g++ -c deque-iterator.cpp

deque.o: deque.cpp deque.h
	g++ -c deque.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o deque *.gch