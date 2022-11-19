all: week1

week1: main.o percolation.o quick-union-weighted.o
	g++ -o week1 main.o percolation.o quick-union-weighted.o

percolation.o: ./tasks/percolation.cpp ./tasks/percolation.h
	g++ -c ./tasks/percolation.cpp

quick-union-weighted.o: ./dsa/quick-union-weighted.cpp ./dsa/quick-union-weighted.h
	g++ -c ./dsa/quick-union-weighted.cpp

main.o: ./tasks/main.cpp
	g++ -c ./tasks/main.cpp

clean:
	rm *.o week1 ./**/*.gch