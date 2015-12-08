CC=g++
CFLAGS=-c -Wall -std=c++11

all:: gsim

gsim: main.o particle.o vector.o bmp.o
	$(CC) main.o particle.o vector.o bmp.o

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

particle.o: particle.cpp
	$(CC) $(CFLAGS) particle.cpp

vector.o: vector.cpp
	$(CC) $(CFLAGS) vector.cpp

bmp.o: bmp.cpp
	 $(CC) $(CFLAGS) bmp.cpp

clean:
	rm *.o
