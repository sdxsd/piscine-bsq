all: program clean

program:
	clang *.c

clean: 
	rm bsq
