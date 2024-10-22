#makefile version 1.0.x

#default value -> gcc
COMPILER = gcc

#default value is empty
CFLAGS = -c -g -nostartfiles -Wall -Wextra -Wstrict-prototypes -Wno-pedantic -Wunused -Wsign-compare -Wconversion -Wno-missing-field-initializers -Wno-missing-braces
CFLAGS=-std=c99

#object files
OBJECTS = main.o source/circular_buffer.o

#executable file direction
INSTALLDIR = ./exec

#todo OBJDIR = ./objects

all: 
	make run
	make install

# $@ means -> target command; run -> $@
run: $(OBJECTS)
	$(COMPILER) -o $@ $(OBJECTS)
	
# main.o: main.c source/circular_buffer.hP
# 	$(COMPILER) $(CFLAGS) main.c

circular_buffer.o: source/circular_buffer.c source/circular_buffer.h
	$(COMPILER) $(CFLAGS) source/circular_buffer.c

#rm -f *.o run, 
#rm -f run ./exec/run,
#rm -f -> $(RM)
#/*.* inside the executable file
clean:
	$(RM) *.o run
	$(RM) $(INSTALLDIR)/*.*

#is it necessary?
install:
	cp run $(INSTALLDIR)

