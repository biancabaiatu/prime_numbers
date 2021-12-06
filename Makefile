CC = g++
CFLAGS = -O0 -Wall -Wextra

build:

	g++ ./Lucas.cpp -g -o testLucas $(CFLAGS)
	g++ ./Solovay-Strassen.cpp -g -o testSolovayStrassen $(CFLAGS)


run-best:
	./testLucas

run-p1:
	./testLucas

run-p2:
	./testSolovayStrassen

.PHONY: clean

clean:
	rm -rf *.o test1 test2 test.in test.out

