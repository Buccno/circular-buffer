#Sample makefile test1.1.x

run: main.o source/circular_buffer.o
	gcc -o run main.o circular_buffer.o
	
main.o: main.c source/circular_buffer.h
	gcc -c main.c

source/circular_buffer.o: source/circular_buffer.c source/circular_buffer.h
	gcc -c source/circular_buffer.c

clean:
	rm -f *.o run
	rm -f run ./exec/run

#isnt necessary?
install:
	cp run ./exec

