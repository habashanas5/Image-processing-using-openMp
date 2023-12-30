CC=g++
CFLAGS = -Wall -O3 -fopenmp
LDFLAGS = -fopenmp
OBJ = program.o
DEPS = program.h


%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
test1: serial
	g++ serial.cpp -o serialcode
	./serialcode oimage.txt edge.txt output.txt

test2: parallel
	g++ -fopenmp parallel.cpp -o parallelized_code
	./parallelized_code oimage.txt edge.txt output2.txt 2

clean:
	rm -f *.o *~ core

