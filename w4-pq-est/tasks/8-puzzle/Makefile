all: program

program: main.o board.o min-pq.o search-node.o solver.o
	g++ -o program main.o board.o min-pq.o search-node.o solver.o

board.o: board.cpp
	g++ -c board.cpp

min-pq.o: min-pq.o
	g++ -c min-pq.cpp

search-node.o: search-node.o
	g++ -c search-node.cpp board.cpp

solver.o: solver.o
	g++ -c solver.cpp board.cpp min-pq.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o program