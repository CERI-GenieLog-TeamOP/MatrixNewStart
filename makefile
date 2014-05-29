all: main.o Matrix.o
	g++ main.o Matrix.o

main.o: main.cpp Matrix.cpp
	g++ -c main.cpp -o main.o 

Matrix.o: Matrix.h Matrix.cpp
	g++ -c Matrix.cpp -o Matrix.o