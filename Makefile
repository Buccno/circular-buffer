#Sample makefile test1.1.x

run: circular_buffer.o
	gcc -o run circular_buffer.o

source/circular_buffer.o: source/circular_buffer.c
	gcc -c source/circular_buffer.c

clean:
	rm -f *.o run