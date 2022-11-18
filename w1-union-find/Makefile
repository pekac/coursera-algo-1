all: week1

week1: main.o percolation.o quick-union-weighted.o
	g++ -o week1 main.o percolation.o quick-union-weighted.o

percolation.o: ./tasks/percolation.cpp ./tasks/percolation.h
	g++ -c ./tasks/percolation.cpp ./tasks/percolation.h

quick-union-weighted.o: ./dsa/quick-union-weighted.cpp ./dsa/quick-union-weighted.h
	g++ -c ./dsa/quick-union-weighted.cpp ./dsa/quick-union-weighted.h


main.o: ./tasks/main.cpp
	g++ -c ./tasks/main.cpp

clean:
	rm *.o week1 ./tasks/percolation.h.gch ./dsa/quick-union-weighted.h.gch